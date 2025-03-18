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
            ArraySequence(T* items, int count) : array(items, count), size(count) {}
            ArraySequence() : array(0), size(0) {};
            ArraySequence(const ArraySequence& arraySequence) : array(arraySequence.array), size(arraySequence.size) {};
            T getFirst();
            T getLast();
            T get(int index);
            int getLength();
            virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
            virtual Sequence<T>* append(T item);
            virtual Sequence<T>* insertAt(T item, int index);
            virtual Sequence<T>* concat(Sequence<T> *list);
            T operator[](int index);
        private:
            DynamicArray<T> array;
            int size;
    protected:
            virtual ArraySequence<T>* Instance() = 0;
    };

    template<class T>
    T ArraySequence<T>::getFirst() {
        if (size < 1)
            throw std::out_of_range("при попытке получения первого элемента ArraySequence пустой");
        return array[0];
    }

    template<class T>
    T ArraySequence<T>::getLast() {
        if (size < 1)
            throw std::out_of_range("при попытке получения последнего элемента ArraySequence пустой");
        return array[size - 1];
    }

    template<class T>
    T ArraySequence<T>::get(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("при попытке получения элемента по индексу ArraySequence индекс за границами");
        return array[index];
    }

    template<class T>
    int ArraySequence<T>::getLength() {
        return size;
    }

    template<class T>
    Sequence<T> *ArraySequence<T>::append(T item) {
        ArraySequence<T>* current = Instance();
        current->size++;
        current->array.resize(current->size);
        current->array.set(current->size-1, item);
        return current;
    }

    template<class T>
    Sequence<T> *ArraySequence<T>::insertAt(T item, int index) {
        ArraySequence<T>* current = Instance();
        current->size++;
        current->array.resize(current->size);
        for (int i = current->size - 1; i > index; --i) {
            current->array[i] = current->array[i - 1];
        }
        current->array[index] = item;
        return current;
    }

    template<class T>
    Sequence<T> *ArraySequence<T>::concat(Sequence<T> *list) {
        ArraySequence<T>* current = Instance();
        for (int i = 0; i < list->getLength(); ++i)
            current->append(list->get(i));
        return current;
    }

    template<class T>
    T ArraySequence<T>::operator[](int index) {
        return this->array[index];
    }

    template<class T>
    class ImmutableArraySequence : public ArraySequence<T> {
    public:
        ImmutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {};
        ImmutableArraySequence() : ArraySequence<T>() {};
        PATypes::Sequence<T>* getSubsequence(int startIndex, int endIndex);
    protected:
        virtual ArraySequence<T>* Instance();
    };

    template<class T>
    Sequence<T> *ImmutableArraySequence<T>::getSubsequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= this->getLength() || endIndex < 0 || endIndex >= this->getLength())
            throw std::out_of_range("Индекс за границами при попытке получения подпоследовательности ImmutableArraySequence");
        ImmutableArraySequence<T>* current = new ImmutableArraySequence<T>(*this);
        for (int i = startIndex; i <= endIndex; ++i) {
            current->append(this->get(i));
        }
        return current;
    }

    template<class T>
    ArraySequence<T> *ImmutableArraySequence<T>::Instance() {
        return new ImmutableArraySequence(*this);
    }

    template<class T>
    class MutableArraySequence : public ArraySequence<T> {
    public:
        MutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {};
        MutableArraySequence() : ArraySequence<T>() {};
        PATypes::Sequence<T>* getSubsequence(int startIndex, int endIndex);
    protected:
        virtual ArraySequence<T>* Instance();
    };

    template<class T>
    Sequence<T> *MutableArraySequence<T>::getSubsequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= this->getLength() || endIndex < 0 || endIndex >= this->getLength())
            throw std::out_of_range("Индекс за границами при попытке получения подпоследовательности MutableArraySequence");
        MutableArraySequence<T>* current = new MutableArraySequence<T>(*this);
        for (int i = startIndex; i <= endIndex; ++i) {
            current->append(this->get(i));
        }
        return current;
    }

    template<class T>
    ArraySequence<T> *MutableArraySequence<T>::Instance() {
        return this;
    }

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
};