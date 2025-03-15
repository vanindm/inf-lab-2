#pragma once

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
    private:
};

template<class T>
class ArraySequence : Sequence<T> {
    public:
        ArraySequence(T* items, int count);
        ArraySequence();
        ArraySequence<T>* getSubsequence(int startIndex, int endIndex);
        ArraySequence<T>* append(T item);
        ArraySequence<T>* insertAt(T item, int index);
};

template<T>
class ListSequence : Sequence<T> {
    public:
        ListSequence(T* items, int count);
        ListSequence();
        ListSequence<T>* getSubsequence(int startIndex, int endIndex);
        ListSequence<T>* append(T item);
        ListSequence<T>* insertAt(T item, int index);
};

};
