#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "stockio.hpp"

// Класс интерпретатора
class Interpreter
{
    private:
        Stock* src;
        bool running;
        StockIO inout;

        void get_command();
        void print_help();

    public:
        Interpreter();
        ~Interpreter();

        // Цикл интерпретатора
        void loop();
};

#endif