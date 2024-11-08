#ifndef COURSE_H    
#define COURSE_H

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
    long double rate;

public:
    Course();
    Course(json);

    // Получить объект в формате JSON
    json get_object();
    // Геттер поля code
    string get_code();
    // Геттер поля rate
    long double get_rate();

    // Консольный вывод
    friend ostream &operator<<(ostream&, const Course&);
    // Консольный ввод
    friend istream &operator>>(istream&, Course&);
    // Сравнение
    bool operator==(Course&);
};

#endif