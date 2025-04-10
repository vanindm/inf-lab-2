#include <iostream>

#include "PATypes/Sequence.h"

#include "argParser.h"

template<class T>
void outputSequence(PATypes::Sequence<T> *sequence) {
	for (PATypes::IEnumerator<T> *enumerator = sequence->getEnumerator(); enumerator = enumerator->moveNext();) {
		std::cout << enumerator->current() << " ";
	}
}

template<class T, class U>
U *inputSequence() {
	U *newSequence;

	int count = 0;
	std::cout << "Введите количество элементов: "; 
	std::cin >> count;
	T* items = new T[count];
	std::cout << "Введите элементы (через любой whitespace символ): ";
	for (int i = 0; i < count; ++i) {
		std::cin >> items[i];
	}

	newSequence = new U(items, count);
	
	delete[] items;

	return newSequence;
}

template<class U>
void outputSequence() {
	
}

int promptMainMenu() {
	int i = 0;
	std::cout << "1. Выбрать АТД\n2. Выйти\n>>>: ";
	std::cin >> i;
	return i;
}

int promptADT() {
	int i = 0;
	std::cout << "1. ImmutableArraySequence\n2. ImmutableListSequence\n3. MutableArraySequence\n4. MutableListSequence\n>>>: ";
	std::cin >> i;
	return i;
}

int main(int argc, char *argv[]) {
	PATypes::MutableListSequence<std::string> argvList;
	for (int i = 0; i < argc; ++i) {
		argvList.append(std::string(argv[i]));
	}
	ArgParser::ArgumentParser argParser;
	argParser.parseArguments(&argvList);
	bool running = true;
	while(running) {
		switch(promptMainMenu())
		{
			case 1:
				switch(promptADT()) {
					case 1:

				}
				break;
			case 2:
				running = false;
				break;
		}
	}
	return 0;
}