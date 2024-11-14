#ifndef COURSE_H   
#define COURSE_H

#include <fstream>
#include "libraries/json.hpp"

using namespace std;
using namespace nlohmann;

// Основной класс
class Course
{
protected:
    string currency;
    string state;
    string code;
    string subunit;
    int fraction;
    double rate;

public:
    string get_currency() { return currency; }
    string get_state() { return state; }
    string get_code() { return code; }
    string get_subunit() { return subunit; }
    int get_fraction() { return fraction; }
    double get_rate() { return rate; }

    void set_currency(string cur) { currency = cur; }
    void set_state(string cur) { state = cur; }
    void set_code(string cur) { code = cur; }
    void set_subunit(string cur) { subunit = cur; }
    void set_fraction(int cur) { fraction = cur; }
    void set_rate(double cur) { rate = cur; }

    // Получить объект в формате JSON
    virtual json get_object() = 0;
};

#endif