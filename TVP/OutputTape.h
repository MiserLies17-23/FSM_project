#pragma once
#include <vector>
#include <string>

class OutputTape
{
public:
	OutputTape();

	void write_state(const char&);
	std::string print_state() const;
private:
	std::vector<char> outputTape;
};