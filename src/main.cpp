#include <iostream>

#include "number_generator.h"
#include "operand.h"
#include "helpers.h"


int main(int, char **)
{
    std::cout << "Hello, world!\n";

    jvvsnol::number_generator<int, -10, 23, 3> a;

    std::cout << a << std::endl;

    auto f1 = [](decltype(a)::value_type arg) { return arg * 2;};

    jvvsnol::operand m(a.begin(), a.end(), f1);
    std::cout << m << std::endl;

    auto f2 = [](decltype(a)::value_type arg) { return arg + 1;};


    jvvsnol::operand n(m.begin(), m.end(), f2);
    std::cout << n << std::endl;

    

    
    return 0;
}
