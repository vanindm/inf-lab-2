#include <cassert>
#include <string>

#include "argParser.h"

int main() {
	ArgParser::ArgumentParser argParser;
	std::string test[] = {"--foo", "foo", "--bar", "bar"};
	PATypes::ImmutableArraySequence<std::string> sequenceArgv(test, 4);
	argParser.parseArguments(&sequenceArgv);
	assert(argParser.getArgument("foo") == "foo");	
	assert(argParser.getArgument("bar") == "bar");	
	return 0;
}