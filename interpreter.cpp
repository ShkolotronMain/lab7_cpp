#include "interpreter.hpp"

Interpreter::Interpreter()
{
    src = new Stock();
    running = 0;
    inout = StockIO();
}

Interpreter::~Interpreter()
{

}

void Interpreter::loop()
{
    running = 1;

    while (running)
        get_command();
}

void Interpreter::get_command()
{
    cout << "[ INP ]> ";

    int res = 0;
    string command;
    cin >> command;

    if (command == "add")
        inout.add_console(src);
    else if (command == "pop")
        inout.pop_console(src);
    else if (command == "read_json")
        inout.json_read(src);
    else if (command == "write_json")
        inout.json_write(*src);
    else if (command == "print")
        inout.print_all(src);
    else if (command == "print_exp")
        inout.print_exp(src);
    else if (command == "help")
        print_help();
    else if (command == "exit")
    {
        cout << "Выход" << endl;
        running = 0;
    }
    else
    {
        cout << "Неверная комманда" << endl;
        cout << "Для получения списка комманд введите help" << endl << endl;   
    }
}

void Interpreter::print_help()
{
    cout << "Список доступных комманд: " << endl;
    cout << "add - добавить в контейнер" << endl;
    cout << "pop - убрать из контейнера" << endl;
    cout << "read_json - ввести несколько из JSON" << endl;
    cout << "write_json - сохранить всё в JSON" << endl;
    cout << "print - вывести все" << endl;
    cout << "print_exp - вывести те, которые дороже USD" << endl;
    cout << "help - список команд" << endl;
    cout << "exit - выход" << endl << endl; 
}
