#include "course.hpp"

// Класс-наследник
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

        json get_object();

        // Консольный вывод
        friend ostream &operator<<(ostream&, const Crypto&);
        // Консольный ввод
        friend istream &operator>>(istream&, Crypto&);
};