#ifndef STOCK_H
#define STOCK_H

#include "classic.hpp"
#include "crypto.hpp"
#include "courseio.hpp"

// Класс-контейнер
class Stock
{
    private:
        Course** mas;
        int cnt;

    public:
        Stock();
        ~Stock();

        Course** get_mas() { return mas; }
        int get_cnt() { return cnt; }

        void set_mas(Course** arg) { mas = arg; };
        void set_cnt(int arg) { cnt = arg; };
        
        void pop(int);
        void add(Course*);
};

#endif