#include <iostream>
#include "rational.hpp"

int main (void) 
{
    rational<int> r(15,20);
    std::cout << r << '\n';
    rational<int> a(3, 0);
    rational<int> b(5, 2);
    rational <int> c = a + r ;
    
    std::cout << "La somma di a e r è: " << c << "\n";
    
    return 0;
}



