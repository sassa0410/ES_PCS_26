#pragma once

#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    for (std::size_t i = 1; i < vec.size(); ++i) {
        if (vec[i-1] > vec[i]) {
            return false;
        }
    }
    return true;
}