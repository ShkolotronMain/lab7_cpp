#include "interpreter.hpp"

Interpreter::Interpreter()
{
    src = new Stock();
    running = 0;
    last = 1;
}

Interpreter::~Interpreter()
{

}

void Interpreter::loop()
{
    running = 1;

    while (running)
    {
        prompt();
        get_command();
    }
}

void Interpreter::prompt()
{
    string c;
    if (last)
        c = "✅";
    else
        c = "❌";
    cout << "[" << c << "]> ";
}

void Interpreter::get_command()
{
    int res = 0;
    string command;
    cin >> command;

    if (command == "add")
        add();
    else if (command == "pop")
        pop();
    else if (command == "read_json")
        read_json();
    else if (command == "write_json")
        write_json();
    else if (command == "print")
        src->print_all();
    else if (command == "print_exp")
        src->print_exp();
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

void Interpreter::add()
{
    Course* nc;
    cout << "Введите желаемый тип валюты" << endl;
    cout << "1 - обычная" << endl;
    cout << "2 - криптовалюта" << endl;

    int num = 1;
    cin >> num;

    if (num == 1)
    {
        nc = new Classic();
        nc->read();
        src->add(nc);
        cout << endl;
    }
    else if (num == 2)
    {
        nc = new Crypto();
        nc->read();
        src->add(nc);
        cout << endl;
    }
    // delete nc;
}

void Interpreter::pop()
{
    int c;
    cout << "Введите индекс удаляемого элемента: ";
    cin >> c;
    last = src->pop(c);
}

void Interpreter::read_json()
{
    string path;
    cout << "Введите путь к файлу" << endl;
    cin >> path;
    last = src->read_from_json(path);
    cout << endl;
}

void Interpreter::write_json()
{
    string path;
    cout << "Введите путь к файлу" << endl;
    cin >> path;
    last = src->write_to_json(path);
    cout << endl;
}
