#pragma once

#include <string>
#include <map>

#include "PATypes/Sequence.h"
#include "PATypes/IEnumerable.h"
#include "PATypes/IEnumerator.h"

namespace ArgParser {
	class ArgumentParser {
		std::map<std::string, std::string> args;

		public:
		ArgumentParser() : args() {}

		void addArgument(std::string arg) {
			args[arg] = "";
		}

		std::string getArgument(std::string arg) {
			return args["--" + arg];
		}

		void parseArguments(PATypes::Sequence<std::string> *input) {
			std::string currentArgument;
			bool isValue = false;
			PATypes::IEnumerator<std::string> *enumerator = input->getEnumerator();
			bool isNotCompleted = true;
			while (isNotCompleted) {
				std::string &currentString = enumerator->current();
				if (currentString.size() >= 2 && 
				currentString[0] == '-'
				&& currentString[1] == '-') {
					currentArgument = currentString;
					isValue = true;
				} else if (isValue) {
					args[currentArgument] = currentString;
					isValue = false;
				}
				isNotCompleted = enumerator->moveNext();
			}
		}
	};
}