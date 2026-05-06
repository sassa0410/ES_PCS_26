# include <iostream>
# include <vector>
# include <string>
# include <cstdlib>
# include "is_sorted.hpp"
# include "quick_sort.hpp"
# include "randfiller.h"


int main() {
    randfiller rf;
    for (int i = 0; i < 100; ++i) {
        std::vector<int> A;
        int random_size = std::rand() % 500 + 1;
        A.resize(random_size);
        rf.fill(A, -100, 100);
        quick_sort(A,0,random_size-1);
        if(!is_sorted(A)) {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> parole = {
        "ciliegia",
        "banana",
        "mela",
        "lime",
        "pera",
        "uva",
        "kiwi",
        "fragola",
        "anguria",
        "melone"
    };
    quick_sort(parole,0,10-1);
    if (!is_sorted(parole)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
    }
