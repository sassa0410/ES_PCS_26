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