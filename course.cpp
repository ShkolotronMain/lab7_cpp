#include "course.hpp"

Course::Course()
{
    currency = "";
    state = "";
    code = "";
    subunit = "";
    fraction = 0;
    rate = 0;
}

Course::Course(json val)
{
    currency = val["currency"];
    state = val["state"];
    code = val["code"];
    subunit = val["subunit"];
    fraction = val["fraction"];
    rate = val["rate"];
}

json Course::get_object()
{
    json value;
    value["currency"] = currency;
    value["state"] = state;
    value["code"] = code;
    value["subunit"] = subunit;
    value["fraction"] = fraction;
    value["rate"] = rate;
    return value;
}

string Course::get_code()
{
    return code;
}

long double Course::get_rate()
{
    return rate;
}

bool Course::operator==(Course& c2)
{
    bool res = 0;

    if (this->get_object() == c2.get_object())
        res = 1;
    else
        res = 0;

    return res;
}

ostream& operator<<(ostream& out, const Course& cl)
{
    out << "===================" << endl;
    out.setf(ios::fixed);
    out.precision(2);
    out << cl.currency << endl;
    out << cl.state << endl;
    out << cl.code << endl;
    out << "1 " + cl.code + " = " << cl.rate << " RUB" << endl;
    out << "===================" << endl;

    return out;
}

istream &operator>>(istream& in, Course& c)
{
    string trash;

    getline(in, trash);
    cout << "Введите название валюты:" << endl;
    getline(in, c.currency);
    cout << "Введите государство:" << endl;
    getline(in, c.state);
    cout << "Введите код валюты:" << endl;
    getline(in, c.code);
    cout << "Введите название разменной валюты:" << endl;
    getline(in, c.subunit);
    cout << "Сколько разменной валюты в основной:" << endl;
    in >> c.fraction;
    cout << "Введите курс валюты к российскому рублю:" << endl;
    in >> c.rate;
    getline(in, trash);

    return in;
}
