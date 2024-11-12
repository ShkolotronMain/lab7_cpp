#ifndef CLASSIC_H
#define CLASSIC_H

#include "course.hpp"

class Classic : public Course
{
    public:
        Classic();
        Classic(json);

        virtual void write() override;
        virtual void read() override;

        virtual json get_object() override;
};

#endif