#include <iostream>

#include "number_generator.h"
#include "helpers.h"

// template <typename T, T value_start, T value_end, T value_step>
// std::ostream& operator<<(std::ostream& os, const jvvsnol::number_generator<T, value_start, value_end, value_step>& a)
// {
//     return os;
// }


int main(int, char **)
{
    std::cout << "Hello, world!\n";

    jvvsnol::number_generator<int, -10, 23, 3> a;

    std::cout << a;


    return 0;
}
