/*
==================================================================================================
Nota per l'esercitazione 4:
  Per realizzare questa esercitazione ho utilizzato un modello IA per la comprensione concettuale
  e per il controllo dell'utilità delle librerie da includere.
==================================================================================================
*/

# include <iostream>
# include <vector>
# include <string>
# include <cstdlib>
# include "is_sorted.hpp"
# include "bubble_sort.hpp"
# include "randfiller.h"

int main() {
    randfiller rf;
    for (int i = 0; i < 100; ++i) {
        std::vector<int> A;
        int random_size = std::rand() % 500 + 1;
        A.resize(random_size);
        rf.fill(A, -100, 100);
        bubble_sort(A);
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
    bubble_sort(parole);
    if (!is_sorted(parole)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
    }

