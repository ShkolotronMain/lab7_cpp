#ifndef STOCK_H
#define STOCK_H

#include "classic.hpp"
#include "crypto.hpp"

// Класс-контейнер
class Stock
{
    private:
        // Массив с курсами валют
        Course** mas;
        // Количество элементов на рынке
        int cnt;

        // Разница двух элементов на рынке
        double diff(Course*, Course*);

    public:
        Stock();
        ~Stock();
        
        bool pop(int);
        void add(Course*);

        bool read_from_json(string);
        bool write_to_json(string);

        void print_all();
        bool print_exp();

        // Запись в JSON
        friend ofstream& operator<<(ofstream&, const Stock&);
        
        // Чтение из JSON
        friend ifstream& operator>>(ifstream&, Stock&);
};

#endif