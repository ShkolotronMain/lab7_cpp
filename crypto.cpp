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
    value["type"] = "crypto";
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

void Crypto::write()
{
    cout << "===================" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << currency << endl;
    cout << state << endl;
    cout << code << endl;
    cout << "1 " + code + " = " << rate << " RUB" << endl;
    cout << "Started in " << year << endl;
    cout << "Written in " << language << endl;
    cout << "===================" << endl;
}

void Crypto::read()
{
    string trash;

    getline(cin, trash);
    cout << "Введите название валюты:" << endl;
    getline(cin, currency);
    cout << "Введите экосистему криптовалют" << endl;
    getline(cin, state);
    cout << "Введите код валюты:" << endl;
    getline(cin, code);
    cout << "Введите курс валюты к российскому рублю:" << endl;
    cin >> rate;
    getline(cin, trash);
    cout << "Введите язык реализации криптовалюты" << endl;
    getline(cin, language);
    cout << "Введите год запуска криптовалюты" << endl;
    cin >> year;
    getline(cin, trash);
}