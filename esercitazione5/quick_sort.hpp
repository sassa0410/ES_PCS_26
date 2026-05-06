#pragma once

#include <vector>
#include "insertion_sort.hpp"

template <typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; ++j) {
        if (A[j] <= x) {
            ++i;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return ++i;
}


// Versione base di Quick Sort
template <typename T>
void quick_sort(std::vector<T>& A, int p, int r)  {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}


// Versione modificata di Quick Sort
template <typename T>
void hybrid_quick_sort(std::vector<T>& A, int p, int r)  {
    if (r-p+1 < 52) {
        insertion_sort(A, p, r);
    }   
    else {
        int q = partition(A, p, r);
        hybrid_quick_sort(A, p, q-1);
        hybrid_quick_sort(A, q+1, r);
    }
}



