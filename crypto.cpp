#include "crypto.hpp"

Crypto::Crypto()
{
    currency = "";
    state = "";
    code = "";
    subunit = "";
    fraction = 0;
    rate = 0;
    language = "";
    year = 0;
}

Crypto::Crypto(json val)
{
    currency = val["currency"];
    state = val["state"];
    code = val["code"];
    subunit = val["subunit"];
    fraction = val["fraction"];
    rate = val["rate"];
    language = val["language"];
    year = val["year"];
}

json Crypto::get_object()
{
    json value;
    value["currency"] = currency;
    value["state"] = state;
    value["code"] = code;
    value["subunit"] = subunit;
    value["fraction"] = fraction;
    value["rate"] = rate;
    value["language"] = language;
    value["year"] = year;
    return value;
}

ostream& operator<<(ostream& out, const Crypto& cl)
{
    out << "===================" << endl;
    out.setf(ios::fixed);
    out.precision(2);
    out << cl.currency << endl;
    out << cl.state << endl;
    out << cl.code << endl;
    out << "1 " + cl.code + " = " << cl.rate << " RUB" << endl;
    out << "Started in " << cl.year << endl;
    out << "Written in " << cl.language << endl;
    out << "===================" << endl;

    return out;
}

istream &operator>>(istream& in, Crypto& c)
{
    string trash;

    getline(in, trash);
    cout << "Введите название валюты:" << endl;
    getline(in, c.currency);
    cout << "Введите экосистему криптовалют" << endl;
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
    cout << "Введите язык реализации криптовалюты" << endl;
    getline(in, c.language);
    cout << "Введите год запуска криптовалюты" << endl;
    in >> c.year;
    getline(in, trash);

    return in;
}