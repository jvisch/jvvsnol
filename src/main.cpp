#include <iostream>

#include "number_generator.h"


int main(int, char**) {
    std::cout << "Hello, world!\n";

    jvvsnol::number_generator<int, 10, 24, 3> g;

    // for(const jvvsnol::number_generator<int, 10, 24, 3>::value_type& i : g)
    for(auto& i : g)
    {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    return 0;
}
