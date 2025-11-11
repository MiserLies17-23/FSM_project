#include "UI.h"
#include "FSM.h"
#include <iostream>
#include <string>

using namespace std;

UI::UI() { setlocale(LC_ALL, "RU"); }

void UI::run()
{   
    cout << "Для начала программы введите цепочку символов. ДЛя выхода из программы введите 0" << endl;
    string input;
    
    cout << "Введите цепочку символов в виде строки: ";
    getline(cin, input);

    while (input != "0")
    {
        try {
            FSM fsm = FSM(InputTape(input));
            cout << fsm.process();
        }
        catch (exception e) {
            cout << "Ошибка! " << e.what();
        }
        cout << "Введите цепочку символов в виде строки: ";
        getline(cin, input);
    }
    cout << "Программа завершила работу.";
}