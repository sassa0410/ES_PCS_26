/*
===================================================================================================
Nota per l'esercitazione 8:
    Ho impiegato l'utilizzo di un assistente IA per comprendere la sintassi e
    l'implementazione ottimale delle funzioni presenti nei contenitori della STL,
    suggeriti nel testo dell'esercitazione.
===================================================================================================
*/

# include <iostream>
# include "unidirected_edge.hpp"
# include "unidirected_graph.hpp"

int main() {
    unidirected_graph<int> G;
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(4,6);
    G.add_edge(1,3);
    G.add_edge(4,5);
    G.add_edge(3,5);

    /* Stampo tutti i nodi */
    std::set<int> nodes = G.all_nodes();
    std::cout << "Nodi presenti: \n";
    for (const auto& node : nodes) {
        std::cout << node << " ";
    }    
    std::cout << "\n\n";


    /* Stampo tutti gli archi */
    std::cout << "Archi presenti: \n" ;
    for(const auto& edge : G.all_edges()) {
        std::cout << edge << "\n";
    }
    std::cout << "\n\n";


    /* Stampo i nodi vicini a un determinato nodo */    
    std::cout << "Nodi vicini al nodo 3: \n" ;
    for (int vicino: G.neighours(3)) {
        std::cout << vicino << " ";
    }
    std::cout << "\n\n";


    /* Stampo la numerazione dato un determinato arco */
    unidirected_edge<int> edge_test(3, 2);
    int num = G.edge_number(edge_test);
    std::cout << "L'arco " << edge_test << " ha ID numerico: " << num << "\n";
    std::cout << "\n\n";


    /* Stampo l'arco data una determinata numerazione */
    std::cout << "L'arco in posizione 0 è: " << G.edge_at(0) << "\n";
    std::cout << "\n\n";


    /* Stampo la differenza tra due grafi */
    unidirected_graph<int> G1;
    G1.add_edge(1,3);
    G1.add_edge(9,10);
    unidirected_graph<int> G2 = G - G1;
        std::cout << "Archi dalla differenza tra G e G1: \n" ;
    for(const auto& edge : G2.all_edges()) {
        std::cout << edge << "\n";
    }
}
