#include <iostream>

#include "PATypes/DynamicArray.h"
#include "PATypes/LinkedList.h"
#include "PATypes/Sequence.h"
#include "PATypes/MapReduce.h"

int sqr(int a) {
    return a * a;
}

int promptSize() {
    int size = 0;
    std::cout << "Введите размер: ";
    std::cin >> size;
    return size;
}

int main()
{
    int* arr = new int[]{1, 2};
    PATypes::LinkedList<int> list(arr, 2);
    PATypes::ImmutableArraySequence<int> seq(arr, 2);
    PATypes::ImmutableArraySequence<int> seq2(arr, 2);
    auto seq3 = PATypes::map(&sqr, &seq);
    auto seqeq = PATypes::MutableArraySequence<int>(seq + seq2);
    for (int i = 0; i < 4; i++) {
        try {
            std::cout << seqeq.get(i) << " ";
        } catch (std::out_of_range& error) {
            std::cout << error.what() << "\n";
        }
    }
    delete[] arr;
    return 0;
}
