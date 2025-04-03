#include <iostream>
#include <vector>

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
	//PATypes::MutableArraySequence<PATypes::MutableArraySequence<int>> asdf;
	int* arr = new int[]{1,2,3};
	PATypes::MutableListSequence<int> a(arr, 3);
	PATypes::MutableListSequence<PATypes::MutableListSequence<int>> asdf(&a, 1);
    std::cout << asdf[0][2] << "\n";
    return 0;
}
