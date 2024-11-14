#ifndef COURSEIO_H
#define COURSEIO_H

#include <iostream>
#include "course.hpp"

class CourseIO
{
    public:
        virtual void write() = 0;
        virtual void read() = 0;
};

#endif