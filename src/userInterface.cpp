#include <iostream>

#include "PATypes/Sequence.h"

template<class T>
void outputSequence(PATypes::Sequence<T> *sequence) {
	for (PATypes::IEnumerator<T> *enumerator = sequence->getEnumerator(); enumerator = enumerator->moveNext();) {
		std::cout << enumerator->current() << " ";
	}
}

template<class T>
PATypes::ImmutableArraySequence<T> *inputArraySequence() {
	PATypes::ImmutableArraySequence<T> *newArraySequence;

	int count = 0;
	std::cin >> count;
	T* items = new T[count];

	newArraySequence = new PATypes::ImmutableArraySequence(T, count);
	
	delete[] items;

	return newArraySequence;
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) {

	}
	return 0;
}