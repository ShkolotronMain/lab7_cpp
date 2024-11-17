#ifndef STOCKIO_H
#define STOCKIO_H

#include "stock.hpp"
#include "courseio.hpp"

class StockIO
{
    private:
        double diff(Course*, Course*);
        bool if_usd(Course*);

    public:
        void print_all(Stock*);
        void print_exp(Stock*);
        void json_read(Stock*);
        void json_write(Stock&);
        void add_console(Stock*);
        void pop_console(Stock*);
};

#endif