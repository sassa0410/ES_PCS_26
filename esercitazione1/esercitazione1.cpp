#include<fstream>
#include<iostream>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "Errore: file mancante\n";
        return 1;
    }
    else {
        std::string filename = argv[1];
        std::ifstream in(filename);
        if (!in) {
            std::cerr << "Errore nell'apertura del file\n";
            return 1;
        }
        else { 
            std::string city;
            while (in >> city) {
                double temp;
                double sum = 0;
                for (int i = 0; i < 4; i++) {
                    in >> temp;
                    sum += temp;
                }
            std::cout << city << ' ' << sum / 4 << "\n";
            }
            return 0;
        }
    }
    
}


/*
Nota per l'esercitazione 1:
Ho sfruttato l'uso di un assistente IA per comprendere esclusivamente:
il funzionamento dell'operatore ">>" e la logica di lettura di un file di testo.
*/

