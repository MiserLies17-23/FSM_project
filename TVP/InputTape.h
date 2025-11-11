#pragma once
#include <string>

class InputTape
{
public:
	InputTape();
	InputTape(const std::string&);

	char get_current_symbol() const;
	void next_position();
	std::string get_input_line() const;
	bool is_end();
private:
	const std::string SYMBOLS;
	int position;
};