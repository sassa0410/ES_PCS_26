#pragma once

#include <vector>
#include <utility>

template <typename T>
void bubble_sort(std::vector<T>& A) {
    if (A.size() <= 1) {
        return;
    }
    
    for (int i = 0; i < int(A.size()) - 1; ++i) {
        for (int j = int(A.size()) - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }

}