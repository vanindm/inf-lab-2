#include <iostream>
#include <cassert>

#include "PATypes/DynamicArray.h"
#include "PATypes/LinkedList.h"
#include "PATypes/Sequence.h"
#include "PATypes/MapReduce.h"

int sqr (int a) {
	return a * a;
}

int sum(int a, int b) {
	return a + b;
}

int main(int argc, char **argv) {
	try {
		int* arr = new int[]{1,2,3,4,5,6};

		PATypes::MutableListSequence<int> mutTest(arr, 6);
		PATypes::ImmutableListSequence<int> immutTest(arr, 6);
		PATypes::Sequence<int> *immutConcat = (immutTest.concat(&mutTest));
		PATypes::ImmutableListSequence<int> concatTest = mutTest + immutTest;
		assert(mutTest[3] == 4);
		assert(immutTest.getCount() == 6);
		assert(immutConcat->getCount() == 12);
		assert(concatTest.getCount() == 12);
		assert(concatTest[6] == 1);

		PATypes::MutableListSequence<PATypes::MutableListSequence<int>> matroskaTest(&mutTest, 1);
		PATypes::MutableListSequence<PATypes::ImmutableListSequence<int>> matroskaTestImmut(&immutTest, 1);
		assert(matroskaTest[0][0] == 1);
		assert(matroskaTestImmut[0][0] == 1);

		PATypes::Sequence<int> *mapTest = map(&sqr, &immutTest);
		assert(mapTest->get(1) == 4);

		int reduceTest = reduce(&sum, &mutTest, 0);
		assert(reduceTest == 42);

		PATypes::IEnumerator<int> *enumerator = mutTest.getEnumerator();
		assert(enumerator->current() == 1);
		enumerator->moveNext();
		assert(enumerator->current() == 2);

		delete enumerator;
		delete[] arr;
		delete mapTest;
		delete immutConcat;
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
		return 1;	
	}
	std::cout << "SUCCESS" << std::endl;
	return 0;
}
