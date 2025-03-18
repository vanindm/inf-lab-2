#include <iostream>
#include "PATypes/DynamicArray.hpp"
#include "PATypes/LinkedList.hpp"
#include "PATypes/Sequence.hpp"

int main()
{
    int* arr = new int[]{1, 2, 3, 4};
    PATypes::LinkedList<int> list(arr, 4);
    int* arr1 = new int[]{1, 2, 3, 4};
    PATypes::LinkedList<int> list1(arr, 4);
    list.concat(&list1);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << list.get(i) << " ";
    }
    delete[] arr;
    delete[] arr1;
    return 0;
}
