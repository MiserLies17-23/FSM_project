#include "InputTape.h"

using namespace std;

InputTape::InputTape() : SYMBOLS{}, position{ -1 } {}
InputTape::InputTape(const string& _symbols) : SYMBOLS{ _symbols }, position{ 0 } {}

char InputTape::get_current_symbol() const
{
	return position < SYMBOLS.length() ? SYMBOLS[position] : '\0';
}

void InputTape::next_position()
{
	position < SYMBOLS.length() ? position++ : position = -1;
}

string InputTape::get_input_line() const
{
	return SYMBOLS;
}

bool InputTape::is_end()
{
	return (position == -1 || position >= SYMBOLS.length());
}