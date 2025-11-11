#pragma once
#include "StateTable.h"
#include "InputTape.h"
#include "OutputTape.h"
#include <regex>

class FSM
{
public:
	FSM(const InputTape&);

	void check();
	void set_state(const char&);
	void update();
	std::string process();
private:
	static const std::regex PATTERN;
	StateTable stateTable;
	InputTape tape;
	OutputTape outputTape;
	char currentState;
};