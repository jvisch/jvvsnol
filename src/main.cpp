#include <iostream>

#include "number_generator.h"

int main(int, char **)
{
    std::cout << "Hello, world!\n";

    jvvsnol::number_generator<int, -10, 23, 2> a;
    for (auto &i : a)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    jvvsnol::number_generator<int, 10, -23, 2> b;
    for (auto &i : b)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    jvvsnol::number_generator<int, -10, -10, 2> c;
    for (auto &i : c)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    jvvsnol::number_generator<int, 10, 44> d;
    for (auto &i : d)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::cout << std::endl;

    return 0;
}
