#ifndef COURSE_H   
#define COURSE_H

#include <fstream>
#include <iostream>
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
    // Получить объект в формате JSON
    virtual json get_object() = 0;
    // Геттер поля code
    string get_code() { return code; }
    // Геттер поля rate
    double get_rate() { return rate; }

    virtual void write() = 0;
    virtual void read() = 0;
};

#endif