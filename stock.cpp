#include "stock.hpp"
#include <fstream>

using namespace nlohmann;

// Конструктор
Stock::Stock()
{
    cnt = 0;
    crint = 0;
    mas = new Course[0];
    crmas = new Crypto[0];
}

// Деструктор
Stock::~Stock()
{
    delete[] mas;
    delete[] crmas;
    cnt = 0;
    crint = 0;
}

bool Stock::pop(int index, bool val)
{
    // добавление обычной валюты
    if (val == 0)
    {
        if (index>=0 && index < cnt)
        {
            int old_cnt = cnt;
            cnt--;
            Course* new_mas = new Course[cnt];
            
            for (int i=0, j=0; i<old_cnt; i++)
                if (i != index)
                {
                    new_mas[j] = mas[i];
                    j++;
                }

            Course* old_mas = mas;
            mas = new_mas;
            delete[] old_mas;

            cout << "Элемент удалён" << endl;
            return 1;
        }
        else
        {
            cerr << "Элемент с заданным индексом не существует" << endl;
            return 0;
        }
    }
    // Добавление криптовалюты
    else
    {
        if (index>=0 && index < crint)
        {
            int old_crint = crint;
            crint--;
            Crypto* new_crmas = new Crypto[crint];
            
            for (int i=0, j=0; i<old_crint; i++)
                if (i != index)
                {
                    new_crmas[j] = crmas[i];
                    j++;
                }

            Crypto* old_crmas = crmas;
            crmas = new_crmas;
            delete[] old_crmas;

            cout << "Элемент удалён" << endl;
            return 1;
        }
        else
        {
            cerr << "Элемент с заданным индексом не существует" << endl;
            return 0;
        }
    }
}

void Stock::print_all()
{
    for (int i=0; i<cnt; i++)
        cout << mas[i];
    for (int i=0; i<crint; i++)
        cout << crmas[i];
}

long double Stock::diff(Course left, Course right)
{
    return (left.get_rate() - right.get_rate());
}

bool Stock::print_exp()
{
    Course usd = {};
    bool usd_exists = 0;

    cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (mas[i].get_code().compare("USD") == 0)
        {
            usd = mas[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, mas[i]) < 0)
                cout << mas[i] << endl;
        
        for (int i=0; i<crint; i++)
            if (diff(usd, crmas[i]) < 0)
                cout << crmas[i] << endl;

        return 1;
    }
    else
    {
        cerr << "\nДоллара в выборке нет, сравнение невозможно" << endl;
        return 0;
    }
        
}

bool Stock::read_from_json(string path)
{
    ifstream in(path);
    
    if (in.is_open())
    {
        in >> *this;
        cout << "Файл прочитан" << endl;
        in.close();
        
        return 1;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
        return 0;
    }
}

bool Stock::write_to_json(string path)
{
    ofstream out(path);
    if (out.is_open())
    {
        out << *this;
        cout << "Файл записан" << endl;
        return 1;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
        return 0;
    }
}

void Stock::operator+=(Course _course)
{
    cnt++;
    Course* new_mas = new Course[cnt];
    for (int i=0; i<cnt-1; i++)
        new_mas[i] = mas[i];
    Course* old_mas = mas;
    mas = new_mas;
    delete[] old_mas;

    mas[cnt-1] = _course;
}

void Stock::operator+=(Crypto _crypto)
{
    crint++;
    Crypto* new_crmas = new Crypto[crint];
    for (int i=0; i<crint-1; i++)
        new_crmas[i] = crmas[i];
    Crypto* old_crmas = crmas;
    crmas = new_crmas;
    delete[] old_crmas;

    crmas[crint-1] = _crypto;
}

ofstream& operator<<(ofstream& out, const Stock& src)
{
    json file;

    file["count"] = src.cnt;
    file["crint"] = src.crint;

    for (int i=0; i<src.cnt; i++)
    {
        json value = src.mas[i].get_object();
        file["values"].push_back(value);
    }

    for (int i=0; i<src.crint; i++)
    {
        json value = src.crmas[i].get_object();
        file["crvalues"].push_back(value);
    }

    out << file.dump(4);
    return out;
}

ifstream& operator>>(ifstream& in, Stock& src)
{
    json file;

    in >> file;

    for (int i=0; i<file["count"]; i++)
    {
        json value = file["values"][i];
        Course nc = Course(value);
        src+=nc;
    }

    for (int i=0; i<file["crint"]; i++)
    {
        json value = file["crvalues"][i];
        Crypto nc = Crypto(value);
        src += nc;
    }
    return in;
}
