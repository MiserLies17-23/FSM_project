#pragma once
#include <map>

class StateTable
{
public:
    StateTable()
    {
        stateTable = {
            {'S', { {'8', 'T'}, {'7', 'U'} }},
            {'T', { {'7', 'F'} }},
            {'M', { {'7', 'N'} }},
            {'N', { {'8', 'O'} }},
            {'O', { {'8', 'S'} }},
            {'U', { {'7', 'W'}, {'8', 'M'} }},     
            {'W', { {'8', 'X'} }},
            {'X', { {'8', 'T'} }},
            {'F', { {'7', 'U'} }}
        };
    }

    char get_next_state(char currentState, char event)
    {
        auto state = stateTable.find(currentState);
        for (auto& sec : state->second)
        {
            if (sec.first == event)
                return sec.second;
        }
        return '\0';
    }

private:
	std::map<char, std::map<char, char>> stateTable;
};
