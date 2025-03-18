#pragma once

#include "LinkedList.hpp"
#include "DynamicArray.hpp"

namespace PATypes
{

template<class T>
class Sequence 
{
    public:
        T getFirst();
        T getLast();
        T get(int index);
        Sequence<T>* getSubsequence(int startIndex, int endIndex);
        Sequence<T>* append(T item);
        Sequence<T>* insertAt(T item, int index);
        Sequence<T>* concat(Sequence<T> *list);
};

template<class T>
class ArraySequence : Sequence<T> {
    public:
        ArraySequence(T* items, int count);
        ArraySequence();
        ArraySequence<T>* getSubsequence(int startIndex, int endIndex);
        ArraySequence<T>* append(T item);
        ArraySequence<T>* insertAt(T item, int index);
    private:
        DynamicArray<T> array;
};

template<class T>
class ListSequence : Sequence<T> {
    public:
        ListSequence(T* items, int count);
        ListSequence();
        ListSequence<T>* getSubsequence(int startIndex, int endIndex);
        ListSequence<T>* append(T item);
        ListSequence<T>* insertAt(T item, int index);
    private:
        LinkedList<T> list;
};

};

template<class T>
PATypes::ArraySequence<T>::ArraySequence(T* items, int count) : array(items, count) {}

template<class T>
PATypes::ArraySequence<T>::ArraySequence() : array(0) {}

template<class T>
PATypes::ArraySequence<T>* PATypes::ArraySequence<T>::getSubsequence(int startIndex, int endIndex)
{

}