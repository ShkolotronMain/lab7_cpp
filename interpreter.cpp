#include "interpreter.hpp"

Interpreter::Interpreter()
{
    src = new Stock();
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
        int com = get_command();
        
        switch (com)
        {
        case 1:
            add();
            break;

        case 2:
            pop();
            break;

        case 3:
            read_json();
            break;

        case 4:
            write_json();
            break;

        case 5:
            src->print_all();
            cout << endl;
            break;
        
        case 6:
            last = src->print_exp();
            cout << endl;
            break;

        case 7:
            print_help();
            break;

        case 8:
            cout << "Выход" << endl;
            running = 0;
            break;

        default:
            cout << "Неверная комманда" << endl;
            cout << "Для получения списка комманд введите help" << endl << endl;
            break;
        }
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

int Interpreter::get_command()
{
    int res = 0;
    string command;
    cin >> command;

    if (command == "add")
        res = 1;
    else if (command == "pop")
        res = 2;
    else if (command == "read_json")
        res = 3;
    else if (command == "write_json")
        res = 4;
    else if (command == "print")
        res = 5;
    else if (command == "print_exp")
        res = 6;
    else if (command == "help")
        res = 7;
    else if (command == "exit")
        res = 8;

    return res;
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
    int inp = 1;
    cout << "Введите тип валюты (1 - обычная, 2 - крипто):" << endl;
    cin >> inp;
    if (inp == 1)
    {
        Course nc = Course();
        cin >> nc;
        *(src)+=nc;
        last = 1;
    }
    else if (inp == 2)
    {
        Crypto nc = Crypto();
        cin >> nc;
        *(src) += nc;
        last = 1;
    }
    else
    {
        last = 0;
        cerr << "Неверно введено число" << endl;
    }
    cout << endl;
}

void Interpreter::pop()
{
    int inp = 1;
    cout << "Введите тип валюты (1 - обычная, 2 - крипто):" << endl;
    cin >> inp;
    if (inp == 1)
    {
        last = 1;
        int c;
        cout << "Введите индекс удаляемого элемента: ";
        cin >> c;
        last = src->pop(c, 0);
    }
    else if (inp == 2)
    {
        last = 1;
        int c;
        cout << "Введите индекс удаляемого элемента: ";
        cin >> c;
        last = src->pop(c, 1);
    }
    else
    {
        last = 0;
        cerr << "Неверно введено число" << endl;
    }
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
