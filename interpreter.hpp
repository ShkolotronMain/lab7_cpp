#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "stock.hpp"

// Класс интерпретатора
class Interpreter
{
    private:
        Stock* src;
        bool running;
        bool last;

        void get_command();
        void prompt();
        void print_help();

        void add();
        void pop();

        void read_json();
        void write_json();

    public:
        Interpreter();
        ~Interpreter();

        // Цикл интерпретатора
        void loop();
};

#endif