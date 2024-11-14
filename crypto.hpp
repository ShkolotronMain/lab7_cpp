#ifndef CRYPTO_H
#define CRYPTO_H

#include "course.hpp"
#include "courseio.hpp"

class Crypto : public Course, public CourseIO
{
    private:
        // язык, на котором написана обработка
        string language;
        // год запуска
        int year;

    public:
        Crypto();
        Crypto(json);

        string get_language() { return language; }
        int get_year() { return year; }

        void set_language(string a) { language = a; }
        void set_year(int a) { year = a; }

        virtual json get_object() override;

        virtual void write() override;
        virtual void read() override;
};

#endif
