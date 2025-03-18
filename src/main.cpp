#include <iostream>
#include "PATypes/DynamicArray.hpp"
#include "PATypes/LinkedList.hpp"
#include "PATypes/Sequence.hpp"

int main()
{
    int* arr = new int[]{1, 2, 3, 4};
    PATypes::LinkedList<int> list(arr, 4);
    PATypes::MutableArraySequence<int> seq(arr, 4);
    PATypes::MutableArraySequence<int> seq2(arr, 4);
    seq.concat(&seq2);
    for (int i = 0; i < 8; i++) {
        std::cout << seq[i] << " ";
    }
    delete[] arr;
    return 0;
}
