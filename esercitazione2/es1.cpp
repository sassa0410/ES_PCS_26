#include <iostream>

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af [8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x =1;
    float y = 1.1;

    (&y)[1]= 0;


    std::cout << &x << "\n";
    std::cout << &y << "\n";
    std::cout << x << "\n";
    return 0;
}

/* NOTA: i due indirizzi di rispettivamente x e y:
        x -> 0x16d11ed88
        y -> 0x16d11ed84
    sono distanti di 4 byte, e quindi, quando si accede a (&y)[1],
    si accede alla posizione di memoria di x, modificandone il valore da 1 a 0. Di conseguenza, quando si stampa x, viene stampato 0 invece di 1. */

