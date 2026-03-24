/* Obiettivo è calcolare:
    - il minimo,
    - il massimo,
    - la media,
    - la deviazione standard.
*/

#include <iostream>
#include <cmath>

int main() {
    static const int N = 10;
    double arr[N] = {8.5, 4.0, 4.5, 11.5, 7.0, 3.0, 12.0, 6.0, 9.0, 10.7};
    double min = arr[0];
    double max = arr[0];
    double media = 0.0;
    for (int i = 0; i < N; ++i) {
        media += arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    media /= N;
    double devstd = 0.0;
    for (int j = 0; j<N; ++j) {
        devstd += std::pow(arr[j] - media, 2);
    }
    devstd = std::sqrt(devstd / N);
    std ::cout << "Min: " << min << "\n";
    std ::cout << "Max: " << max << "\n";
    std ::cout << "Media: " << media << "\n";
    std ::cout << "Deviazione standard: " << devstd << "\n";
    
    // Facoltativo: ordinamento Bubblesort.
    int k = 1;
    while(k > 0) {
        k = 0;
        for (int i = 0; i < N - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i],arr[i+1]);
                k=1;
            }
        }
    }
    std ::cout << "Array ordinato: ";
    for (int i = 0; i < N; ++i) {
        std ::cout << arr[i] << " ";
    }
    std ::cout << "\n";
    
    return 0;
}