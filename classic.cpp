#include "classic.hpp"

Classic::Classic()
{
    currency = "";
    state = "";
    code = "";
    subunit = "";
    fraction = 0;
    rate = 0;
}

Classic::Classic(json val)
{
    currency = val["currency"];
    state = val["state"];
    code = val["code"];
    subunit = val["subunit"];
    fraction = val["fraction"];
    rate = val["rate"];
}

json Classic::get_object()
{
    json value;
    value["type"] = "classic";
    value["currency"] = currency;
    value["state"] = state;
    value["code"] = code;
    value["subunit"] = subunit;
    value["fraction"] = fraction;
    value["rate"] = rate;
    return value;
}

void Classic::write()
{
    cout << "===================" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << currency << endl;
    cout << state << endl;
    cout << code << endl;
    cout << "1 " + code + " = " << rate << " RUB" << endl;
    cout << "===================" << endl;
}

void Classic::read()
{
    string trash;

    getline(cin, trash);
    cout << "Введите название валюты:" << endl;
    getline(cin, currency);
    cout << "Введите государство:" << endl;
    getline(cin, state);
    cout << "Введите код валюты:" << endl;
    getline(cin, code);
    cout << "Введите название разменной валюты:" << endl;
    getline(cin, subunit);
    cout << "Сколько разменной валюты в основной:" << endl;
    cin >> fraction;
    cout << "Введите курс валюты к российскому рублю:" << endl;
    cin >> rate;
    getline(cin, trash);
}