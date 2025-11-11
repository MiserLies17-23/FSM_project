#include "OutputTape.h"
#include <iostream>

using namespace std;

OutputTape::OutputTape() : outputTape{} {}

void OutputTape::write_state(const char& newState)
{
	outputTape.push_back(newState);
}

string OutputTape::print_state() const
{
	string output;
	for (auto state : outputTape)
		output = output + state + " -> ";
	output += "e";
	return output;
}