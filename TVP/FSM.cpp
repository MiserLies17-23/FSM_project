#include "FSM.h"
#include <iostream>

using namespace std;

const regex FSM::PATTERN{ "87(78788|77887)*" };

FSM::FSM(const InputTape& _tape) : tape{ _tape }, currentState{ 'S' }
{
	outputTape.write_state(currentState);
}

void FSM::check()
{
	if (tape.get_input_line().empty()) throw exception("Пустая строка!\n"); 
	for (char c : tape.get_input_line())
	{
		if (c != '7' && c != '8') throw exception("Цепочка не является допустимой - строка содержит недопустимые символы!\n");
	}
}

void FSM::set_state(const char& newState)
{
	currentState = newState;
	outputTape.write_state(newState);
}

void FSM::update()
{	
	while (!tape.is_end())
	{
		char event = tape.get_current_symbol();
		char newState = stateTable.get_next_state(currentState, event);

		if (newState == '\0') throw exception("Переход невозможен - нет перехода!\n");
		
		set_state(newState);
		tape.next_position();
	}
	if (!regex_match(tape.get_input_line(), PATTERN)) throw exception("Не достигнуто конечное состояние!\n");
}

string FSM::process()
{
	check();
	update();

	string resultMessage = "Цепочка является допустимой!\n";
	resultMessage += "Переходы состояний: " + outputTape.print_state() + "\n";
	
	return resultMessage;
}

