#ifndef STOCKIO_H
#define STOCKIO_H

#include "stock.hpp"
#include "courseio.hpp"

class StockIO
{
    private:
        double diff(Course* left, Course* right);

    public:
        void print_all(Stock*);
        void print_exp(Stock*);
        void json_read(string, Stock*);
        void json_write(string, Stock);
};

#endif