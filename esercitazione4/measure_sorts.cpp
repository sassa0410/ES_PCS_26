/*
==================================================================================================
Nota per l'esercitazione 4:
  Per realizzare questa esercitazione ho utilizzato un modello IA per la comprensione concettuale
  e per il controllo dell'utilità delle librerie da includere.
==================================================================================================
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

#include "randfiller.h"
#include "timecounter.h"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"

 int main() {
    randfiller rf;
    for (int i = 4; i < 10000; i *= 2) {
        std::vector<int> A(i);
        rf.fill(A, -100, 100);
        std::vector<int> B = A;
        std::vector<int> C = A;
        std::vector<int> D = A;

        timecounter tc;
        tc.tic();
        bubble_sort(A);
        double secs_A = tc.toc(); /* stop the timecounter, get time and print it */

        tc.tic();
        insertion_sort(B);
        double secs_B = tc.toc();
    
        tc.tic();
        selection_sort(C);
        double secs_C = tc.toc();
    
        tc.tic();
        std::sort(D.begin(), D.end());
        double secs_D = tc.toc();

        std::cout << "Size: " << i 
                  << " Bubble: " << secs_A << "s"
                  << " Insertion: " << secs_B << "s"
                  << " Selection: " << secs_C << "s"
                  << " std::sort: " << secs_D << "s\n";
    }
}


