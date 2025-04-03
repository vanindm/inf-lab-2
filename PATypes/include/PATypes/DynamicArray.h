#pragma once
#include <cstring>
#include <stdexcept>

namespace PATypes {

    template<class T>
    class DynamicArray {
    public:
        DynamicArray(T *items, int count);
        DynamicArray(int size);
        DynamicArray(const DynamicArray<T> &dynamicArray);
        DynamicArray(int size, const DynamicArray<T> &dynamicArray);
        ~DynamicArray();
        T get(int index);
        int getSize();
        void set(int index, T value);
        void resize(int newSize);
        T &operator[](int index);
        T &operator[](const int& index) const;
        PATypes::DynamicArray<T> &operator=(const DynamicArray<T>& array);

    private:
        T *items;
        int size;
    };

}// namespace PATypes

template<class T>
PATypes::DynamicArray<T>::DynamicArray(T *items, int count) : size(count) {
    this->items = new T[count];
    for (int i = 0; i < size; ++i) {
        this->items[i] = T(items[i]);
    }
}

template<class T>
PATypes::DynamicArray<T>::DynamicArray(int size) : size(size) {
    this->items = new T[size];
    std::memset(this->items, sizeof(T), size);
}

template<class T>
PATypes::DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) : size(dynamicArray.size) {
    this->items = new T[this->size];
    for (int i = 0; i < size; ++i) {
        this->items[i] = T(dynamicArray[i]);
    }
}

template<class T>
PATypes::DynamicArray<T>::DynamicArray(int size, const DynamicArray<T> &dynamicArray) : size(size) {
    this->items = new T[this->size];
    for (int i = 0; i < size; ++i) {
        this->items[i] = T(dynamicArray[i]);
    }
}

template<class T>
PATypes::DynamicArray<T>::~DynamicArray() {
    delete[] items;
}

template<class T>
T PATypes::DynamicArray<T>::get(int index) {
    if (index < 0 || index > this->size)
        throw std::out_of_range("Попытка обращения к элементу за границами динамического массива");
    return this->items[index];
}

template<class T>
int PATypes::DynamicArray<T>::getSize() {
    return this->size;
}

template<class T>
void PATypes::DynamicArray<T>::set(int index, T value) {
    this->items[index] = value;
}

template<class T>
void PATypes::DynamicArray<T>::resize(int newSize) {
    T *newItems = new T[newSize];
    for (int i = 0; i < size; ++i) {
        newItems[i] = T(items[i]);
    }
    this->size = newSize;
    delete[] this->items;
    this->items = newItems;
}

template<class T>
T &PATypes::DynamicArray<T>::operator[](int index) {
    if (index < 0 || index > this->size - 1)
        throw std::out_of_range("Попытка обращения к элементу за границами динамического массива");
    return this->items[index];
}

template<class T>
T &PATypes::DynamicArray<T>::operator[](const int& index) const {
    if (index < 0 || index > this->size - 1)
        throw std::out_of_range("Попытка обращения к элементу за границами динамического массива");
    return this->items[index];
}

template<class T>
PATypes::DynamicArray<T> &PATypes::DynamicArray<T>::operator=(const PATypes::DynamicArray<T>& array) {
    if (this->items)
        delete this->items;
    this->size = array.size;
    this->items = new T[this->size];
    for (int i = 0; i < size; ++i) {
        this->items[i] = T(array[i]);
    }
    return *this;
}
