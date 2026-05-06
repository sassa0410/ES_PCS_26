/*
===================================================================================================
Nota per l'esercitazione 5:
  Ho impiegato un modello IA unicamente per la corretta configurazione di CMake in debug e release.
===================================================================================================
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>

#include "randfiller.h"
#include "timecounter.h"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"


 int main() {
    std::vector<std::vector<int>> V(100);
    randfiller rf;
    timecounter tc;
    for (int i = 0; i < 100; ++i) {
        std::vector<int> A(2000);
        rf.fill(A, -100, 100);
        V[i] = A;
    }
    std::vector<std::vector<int>> A = V;  
    std::vector<std::vector<int>> B = V;
    std::vector<std::vector<int>> C = V;
    std::vector<std::vector<int>> D = V;
    std::vector<std::vector<int>> E = V;
    std::vector<std::vector<int>> F = V;
    std::vector<std::vector<int>> G = V;    

    tc.tic();
    for (int j = 0; j < 100;++j) {
        bubble_sort(A[j]);
    }
    double secs_A = tc.toc();


    tc.tic();
    for (int j = 0; j < 100;++j) {
        insertion_sort(B[j]);
    }
    double secs_B = tc.toc();


    tc.tic();
    for (int j = 0; j < 100;++j) {
        selection_sort(C[j]);
    }
    double secs_C = tc.toc();


    tc.tic();
    for (int j = 0; j < 100;++j) {
        merge_sort(D[j],0,D[j].size()-1);
    }
    double secs_D = tc.toc();


    tc.tic();
    for (int j = 0; j < 100;++j) {
        hybrid_quick_sort(E[j],0,E[j].size()-1);
    }
    double secs_E = tc.toc();



    tc.tic();
    for (int j = 0; j < 100;++j) {
        std::sort(F[j].begin(), F[j].end());
    }
    double secs_F = tc.toc();


    tc.tic();
    for (int j = 0; j < 100;++j) {
        hybrid_quick_sort(G[j],0,G[j].size()-1);
    }
    double secs_G = tc.toc();    


    std::cout << "STAMPA DI TEST CON VETTORI DI " << E[0].size() << " ELEMENTI:\n"
              << " Bubble:         " << secs_A /100 << "s\n"
              << " Insertion:      " << secs_B /100 << "s\n"
              << " Selection:      " << secs_C /100 << "s\n"
              << " Merge:          " << secs_D /100 << "s\n"
              << " Hybrid Quick:   " << secs_E /100 << "s\n"
              << " Quick (base):   " << secs_G /100 << "s\n"
              << " Std::sort:      " << secs_F /100 << "s\n";
}