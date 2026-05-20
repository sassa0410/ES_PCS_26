/*
===================================================================================================
Nota per l'esercitazione 9:
    Ho utilizzato un'IA come supporto per configurare Graphviz sul Mac e comprendere i
    comandi da terminale necessari a trasformare i file .dot nelle immagini dei grafi.    
===================================================================================================
*/


# include <iostream>
# include "unidirected_graph.hpp"
# include "container_LIFO.hpp"
# include "container_FIFO.hpp"
# include "graph_visit.hpp"
# include "recursive_dfs.hpp"
# include "dijkstra.hpp"

int main() {
    unidirected_graph<int> G;

    G.add_edge(1,2);
    G.add_edge(1,3);
    G.add_edge(1,4);
    G.add_edge(1,6);
    G.add_edge(2,4);
    G.add_edge(2,5);
    G.add_edge(2,7);
    G.add_edge(3,6);
    G.add_edge(4,6);
    G.add_edge(4,7);
    G.add_edge(5,7);
    G.add_edge(6,7);
    G.add_edge(6,8);
    G.add_edge(7,9);
    G.add_edge(8,9);
    G.save_to_dot("Graph.dot");

    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    dfsG.save_to_dot("dfs.dot");


    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    bfsG.save_to_dot("bfs.dot");


    auto recursive_dfsG = recursive_dfs(G, 1);
    recursive_dfsG.save_to_dot("recursive_dfs.dot");


    int nodo_inizio = 1;
    auto [distanze, predecessori] = dijkstra(G, nodo_inizio);
    std::cout << "TEST ALGORITMO DI DIJKSTRA:" << std::endl;
    for (int nodo : G.all_nodes()) {
        std::cout << "Distanza verso il nodo " << nodo << " = " << distanze[nodo] << " salti\n";
    }
    std::cout << std::endl;
    for (int nodo : G.all_nodes()) {
        std::cout << "Per arrivare a " << nodo << ", il passo precedente e': " << predecessori[nodo] << "\n";
    }
    return 0;
}