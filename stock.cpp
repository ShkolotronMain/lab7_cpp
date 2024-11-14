#include "stock.hpp"

using namespace nlohmann;

// Конструктор
Stock::Stock()
{
    cnt = 0;
    mas = new Course*[0];
}

// Деструктор
Stock::~Stock()
{
    delete[] mas;
    cnt = 0;
}

void Stock::pop(int index)
{
    if (index>=0 && index < cnt)
    {
        int old_cnt = cnt;
        cnt--;
        Course** new_mas = new Course*[cnt];
        
        for (int i=0, j=0; i<old_cnt; i++)
            if (i != index)
            {
                new_mas[j] = mas[i];
                j++;
            }

        Course** old_mas = mas;
        mas = new_mas;
        delete[] old_mas;

        cout << "Элемент удалён" << endl;
    }
    else
    {
        cerr << "Элемент с заданным индексом не существует" << endl;
    }
}

void Stock::add(Course* ptr)
{
    cnt++;
    Course** new_mas = new Course*[cnt];
    for (int i=0; i<cnt-1; i++)
        new_mas[i] = mas[i];
    Course** old_mas = mas;
    mas = new_mas;
    delete[] old_mas;

    mas[cnt-1] = ptr;
}
