#pragma once

#include <vector>
#include <utility>

template <typename T>
void selection_sort(std::vector<T>& A) {
    if (A.size() <= 1) {
        return;
    }
    
    for (int i = 0; i < int(A.size()) - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < int(A.size()); ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }

}