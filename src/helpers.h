#pragma once

#ifndef JVVSNOL_HELPERS_H__
#define JVVSNOL_HELPERS_H__

#include <iostream>

#include "number_generator.h"
#include "operand.h"

namespace jvvsnol
{
    template <typename T, T value_start, T value_end, T value_step=1>
    std::ostream &operator<<(std::ostream &os, const number_generator<T, value_start, value_end, value_step> &rhs)
    {
        auto begin = rhs.begin();
        os << '[' << (*begin);
        while ((++begin) != rhs.end())
        {
            os << ',' << (*begin);
        }
        os << ']';
        return os;
    }

    template <typename T_iter>
    std::ostream &operator<<(std::ostream &os, const class operand<T_iter> &rhs)
    {
        auto begin = rhs.begin();
        os << '[' << (*begin);
        while ((++begin) != rhs.end())
        {
            os << ',' << (*begin);
        }
        os << ']';
        return os;

    }
}

#endif // JVVSNOL_HELPERS_H__