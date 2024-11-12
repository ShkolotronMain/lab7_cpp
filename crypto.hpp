#ifndef CRYPTO_H
#define CRYPTO_H

#include "course.hpp"

class Crypto : public Course
{
    private:
        // язык, на котором написана обработка
        string language;
        // год запуска
        int year;

    public:
        Crypto();
        Crypto(json);

        virtual json get_object() override;

        virtual void write() override;
        virtual void read() override;
};

#endif
