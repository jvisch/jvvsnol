#include <iostream>

#include "number_generator.h"
#include "operand.h"
#include "helpers.h"


int main(int, char **)
{
    std::cout << "Hello, world!\n";

    jvvsnol::number_generator<int, -10, 23, 3> a;

    std::cout << a << std::endl;

    jvvsnol::operand m(a.begin(), a.end());
    std::cout << m << std::endl;

    jvvsnol::operand n(m.begin(), m.end());
    std::cout << n << std::endl;

    
    // std::cout << std::endl;
    // for(auto& x : m)
    // {
    //     std::cout << x << " - ";
    // }
    // std::cout << std::endl;

    // jvvsnol::operand n(m.begin(), m.end());
    // for(auto& x : n)
    // {
    //     std::cout << x << " - ";
    // }
    std::cout << std::endl;

    jvvsnol::number_generator<int, 8, 5> z;
    std::cout << z << std::endl;
    
    jvvsnol::number_generator<int, 8, 8> q;
    std::cout << q << std::endl;
    
    return 0;
}
