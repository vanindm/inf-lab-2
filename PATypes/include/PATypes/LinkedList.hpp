#pragma once

namespace PATypes
{

template<class T>
class LinkedList
{
    public:
        LinkedList(T* items, int count);
        LinkedList();
        LinkedList(const LinkedList<T>& list);
        T getFirst();
        T getLast();
        T get(int index);
        LinkedList<T>* getSubList(int startIndex, int endIndex);
        int getLength();
        void append(T item);
        void prepend(T item);
        void insertAt(T item, int index);
        LinkedList<T>* concat(LinkedList<T> *list);
    private:
};

};
