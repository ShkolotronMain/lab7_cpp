#ifndef STOCK_H
#define STOCK_H

#include "crypto.hpp"

// Класс-контейнер
class Stock
{
    private:
        // Массив с курсами валют
        Course* mas;
        Crypto* crmas;

        // Количество элементов на рынке
        int cnt;
        int crint;

        // Разница двух элементов на рынке
        long double diff(Course, Course);

    public:
        Stock();
        ~Stock();
        
        bool pop(int, bool);

        bool read_from_json(string);
        bool write_to_json(string);

        void print_all();
        bool print_exp();

        // Добавление элемента на рынок
        void operator+=(Course);
        void operator+=(Crypto);

        // Запись в JSON
        friend ofstream& operator<<(ofstream&, const Stock&);
        // Чтение из JSON
        friend ifstream& operator>>(ifstream&, Stock&);
};

#endif