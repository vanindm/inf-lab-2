#include <iostream>

#include "PATypes/DynamicArray.h"
#include "PATypes/LinkedList.h"
#include "PATypes/Sequence.h"
#include "PATypes/MapReduce.h"

int sqr(int a) {
    return a * a;
}

int main()
{
    int* arr = new int[]{1, 2, 3, 4};
    PATypes::LinkedList<int> list(arr, 4);
    PATypes::MutableListSequence<int> seq(arr, 4);
    PATypes::ImmutableArraySequence<int> seq2(arr, 4);
    auto seq3 = PATypes::map(&sqr, &seq);
    seq.concat(&seq2);
    for (int i = 0; i < 8; i++) {
        try {
            std::cout << seq3->get(i) << " ";
        } catch (std::out_of_range& error) {
            std::cout << error.what() << "\n";
        }
    }
    delete[] arr;
    return 0;
}
