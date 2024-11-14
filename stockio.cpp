#include "stockio.hpp"

double StockIO::diff(Course* left, Course* right) 
{ 
    return (left->get_rate() - right->get_rate());
}

void StockIO::print_all(Stock src)
{
    for (int i=0; i<src.get_cnt(); i++)
        src.get_mas_io()[i]->write();
}

void StockIO::print_exp(Stock src)
{
    Course* usd = {};
    bool usd_exists = 0;
    Course** mas = src.get_mas();
    CourseIO** mas_io = src.get_mas_io();
    int cnt = src.get_cnt();

    cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (mas[i]->get_code().compare("USD") == 0)
        {
            usd = mas[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, mas[i]) < 0)
            {
                mas_io[i]->write();
                cout << endl;
            }
    }
    else
    {
        cerr << "\nДоллара в выборке нет, сравнение невозможно" << endl;
    }
}

void StockIO::json_read(string path, Stock src)
{
    ifstream in(path);
    if (in.is_open())
    {
        json file;

        in >> file;

        for (int i=0; i<file["values"].size(); i++)
        {
            json value = file["values"][i];
            CourseIO* nc;
            if (value["type"] == "classic")
            {
                nc = new Classic(value);
            }
            else if (value["type"] == "crypto")
            {
                nc = new Crypto(value);
            }
            src.add((Course*)nc);
        }

        cout << "Файл прочитан" << endl;
        in.close();
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }
}

void StockIO::json_write(string path, Stock src)
{
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
}