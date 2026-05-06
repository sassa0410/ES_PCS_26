// Versione adattata di Insertion Sort per l'Hybrid Quick Sort
#pragma once

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        for (int j = p+1; j <= r; ++j) {
            T key = A[j];
            int i = j - 1;
            while (i >= p && A[i] > key) {
                A[i + 1] = A[i];
                --i;
            }
            A[i + 1] = key;
        }
} 
}

template <typename T>
void insertion_sort(std::vector<T>& A) {
    if (!A.empty()) {
    insertion_sort(A, 0, A.size() - 1);
    }
}



// Versione precedente di Insertion Sort
/*
#pragma once

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& A) {
    if (A.size() <= 1) {
        return;
    }
    
    for (int j = 1; j < int(A.size()); ++j) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }

}
    */