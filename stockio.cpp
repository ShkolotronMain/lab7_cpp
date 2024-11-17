#include "stockio.hpp"

double StockIO::diff(Course* left, Course* right) 
{ 
    return (left->get_rate() - right->get_rate());
}

bool StockIO::if_usd(Course* arg)
{
    return (arg->get_code() == "USD");
}

void StockIO::print_all(Stock* src)
{
    for (int i=0; i<src->get_cnt(); i++)
    {
        if (typeid(*(src->get_mas()[i])) == typeid(Classic))
        {
            Classic* save = static_cast<Classic*>(src->get_mas()[i]);
            save->write();
        }
        else if (typeid(*src->get_mas()[i]) == typeid(Crypto))
        {
            Crypto* save = static_cast<Crypto*>(src->get_mas()[i]);
            save -> write();
        }
    }
}

void StockIO::print_exp(Stock* src)
{
    Course* usd = {};
    bool usd_exists = 0;
    int cnt = src->get_cnt();

    cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (src->get_mas()[i]->get_code().compare("USD") == 0)
        {
            usd = src->get_mas()[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, src->get_mas()[i]) < 0)
            {
                if (typeid(*src->get_mas()[i]) == typeid(Classic))
                    static_cast<Classic*>(src->get_mas()[i])->write();
                else if (typeid(*src->get_mas()[i]) == typeid(Crypto))
                    static_cast<Crypto*>(src->get_mas()[i])->write();

                cout << endl;
            }
    }
    else
    {
        cerr << "\nДоллара в выборке нет, сравнение невозможно" << endl;
    }
}

void StockIO::json_read(Stock* src)
{
    string path;
    cout << "Введите путь к файлу" << endl;
    cin >> path;

    ifstream in(path);
    if (in.is_open())
    {
        json file;

        in >> file;

        for (int i=0; i<file["values"].size(); i++)
        {
            json value = file["values"][i];
            Course* nc;
            if (value["type"] == "classic")
            {
                nc = new Classic(value);
                src->add(nc);
            }
            else if (value["type"] == "crypto")
            {
                nc = new Crypto(value);
                src->add(nc);
            }
        }

        cout << "Файл прочитан" << endl;
        in.close();
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }

    cout << endl;
}

void StockIO::json_write(Stock& src)
{
    string path;
    cout << "Введите путь к файлу" << endl;
    cin >> path;

    ofstream out(path);
    if (out.is_open())
    {
        json file;

        for (int i=0; i<src.get_cnt(); i++)
        {
            json value = src.get_mas()[i]->get_object();
            file["values"].push_back(value);
        }

        out << file.dump(4);
        cout << "Файл записан" << endl;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }

    cout << endl;
}

void StockIO::add_console(Stock* src)
{
    cout << "Введите желаемый тип валюты" << endl;
    cout << "1 - обычная (по умол.)" << endl;
    cout << "2 - криптовалюта" << endl;
    int num = 1;
    cin >> num;

    Course* nc;

    if (num != 2)
    {
        nc = new Classic();
        static_cast<Classic*>(nc)->read();
    }
    else
    {
        nc = new Crypto();
        static_cast<Crypto*>(nc)->read();
    }

    src->add(nc);

    cout << endl;
}

void StockIO::pop_console(Stock* src)
{
    string code;
    cout << "Введите код удаляемого элемента: ";
    cin >> code;

    bool is_found=0;

    for (int i=0; i<src->get_cnt() && !is_found; i++)
    {
        if (src->get_mas()[i]->get_code() == code)    
        {
            src->pop(i);
            is_found = 1;
        }
    }

    cout << endl;
}