#pragma once

#include "LinkedList.hpp"
#include "DynamicArray.hpp"

namespace PATypes
{

template<class T>
class Sequence 
{
    public:
        virtual T getFirst() = 0;
        virtual T getLast() = 0;
        virtual T get(int index) = 0;
        virtual int getLength() = 0;
        virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
        virtual Sequence<T>* append(T item) = 0;
        virtual Sequence<T>* insertAt(T item, int index) = 0;
        virtual Sequence<T>* concat(Sequence<T> *list) = 0;
};

template<class T>
class ArraySequence : public Sequence<T> {
    public:
        ArraySequence(T* items, int count);
        ArraySequence();
        ArraySequence(const ArraySequence& arraySequence);
        virtual T getFirst();
        virtual T getLast();
        virtual T get(int index);
        virtual int getLength();
        virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
        virtual Sequence<T>* append(T item);
        virtual Sequence<T>* insertAt(T item, int index);
        virtual Sequence<T>* concat(Sequence<T> *list);
    private:
        DynamicArray<T> array;
        int size;
        virtual Sequence<T>* Instance() = 0;
};

template<class T>
class ListSequence : public Sequence<T> {
    public:
        ListSequence(T* items, int count);
        ListSequence();
        virtual Sequence<T>* getSubsequence(int startIndex, int endIndex);
        virtual Sequence<T>* append(T item);
        virtual Sequence<T>* insertAt(T item, int index);
    private:
        LinkedList<T> list;
        int size;
};

template<class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    ImmutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {};
    ImmutableArraySequence() : ArraySequence<T>() {};
    ImmutableArraySequence(const ImmutableArraySequence<T>& arraySequence) : ArraySequence<T>(arraySequence) {};
    PATypes::Sequence<T>* getSubsequence(int startIndex, int endIndex);
private:
    virtual Sequence<T>* Instance();
};

template<class T>
class MutableArraySequence : public ArraySequence<T> {
public:
    MutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {};
    MutableArraySequence() : ArraySequence<T>() {};
    PATypes::Sequence<T>* getSubsequence(int startIndex, int endIndex);
private:
    virtual Sequence<T>* Instance();
};

};

template<class T>
PATypes::ArraySequence<T>::ArraySequence(T* items, int count) : array(items, count), size(count) {}

template<class T>
PATypes::ArraySequence<T>::ArraySequence() : array(0), size(0) {}

template<class T>
PATypes::ArraySequence<T>::ArraySequence(const PATypes::ArraySequence<T>& arraySequence) : array(arraySequence.array), size(arraySequence.size) {}

template<class T>
T PATypes::ArraySequence<T>::getFirst()
{
    if (size < 1)
        throw std::out_of_range("при попытке получения первого элемента ArraySequence пуст");
    return array[0];
}

template<class T>
T PATypes::ArraySequence<T>::getLast()
{
    if (size < 1)
        throw std::out_of_range("при попытке получения последнего элемента ArraySequence пуст");
    return array[size - 1];
}

template<class T>
T PATypes::ArraySequence<T>::get(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("при попытке получения элемента по индексу ArraySequence индекс вне границ ArraySequence");
    return array[index];
}

template<class T>
int PATypes::ArraySequence<T>::getLength()
{
    return size;
}

template<class T>
PATypes::Sequence<T>* PATypes::MutableArraySequence<T>::getSubsequence(int startIndex, int endIndex)
{
    if (startIndex < 0 || startIndex >= Instance()->getLength() || endIndex < 0 || endIndex >= Instance()->getLength())
        throw std::out_of_range("При попытке получения подпоследовательности ArraySequence индекс за границами");
    T* newItems = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i < endIndex; ++i)
        newItems[i] = ((MutableArraySequence<T> *)Instance())->get(i);
    Sequence<T>* subSequence = (new MutableArraySequence<T>(newItems, endIndex - startIndex + 1))->Instance();
    delete[] newItems;
    return subSequence;
}

template<class T>
PATypes::Sequence<T>* PATypes::ImmutableArraySequence<T>::getSubsequence(int startIndex, int endIndex)
{
    if (startIndex < 0 || startIndex >= Instance()->getLength() || endIndex < 0 || endIndex >= Instance()->getLength())
        throw std::out_of_range("При попытке получения подпоследовательности ArraySequence индекс за границами");
    T* newItems = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i < endIndex; ++i)
        newItems[i] = ((ImmutableArraySequence<T> *)Instance())->get(i);
    Sequence<T>* subSequence = (new ImmutableArraySequence<T>(newItems, endIndex - startIndex + 1))->Instance();
    delete[] newItems;
    return subSequence;
}

template<class T>
PATypes::Sequence<T>* PATypes::ArraySequence<T>::append(T item) {
    size++;
    array.resize(size);
    array.set(size-1, item);
    return Instance();
}

template<class T>
PATypes::Sequence<T>* PATypes::ArraySequence<T>::insertAt(T item, int index) {
    size++;
    array.resize(size);
    for(int i = size - 1; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = item;
    return Instance();
}

template<class T>
PATypes::Sequence<T>* PATypes::ArraySequence<T>::concat(PATypes::Sequence<T> *list) {
    for (int i = 0; i < list->getLength(); ++i)
    {
        append(list->get(i));
    }
    return Instance();
}

template<class T>
PATypes::Sequence<T>* PATypes::ImmutableArraySequence<T>::Instance() {
    return new ImmutableArraySequence<T>(*this);
}


template<class T>
PATypes::Sequence<T>* PATypes::MutableArraySequence<T>::Instance() {
    return this;
}
