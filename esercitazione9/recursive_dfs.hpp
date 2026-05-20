# pragma once
# include <set>
# include "unidirected_graph.hpp"

template<typename T>
void dfs_function (unidirected_graph<T>& G, std::set<T>& visited, T node, unidirected_graph<T>& final_tree) {
    visited.insert(node);

    for (T vicino : G.neighours(node)) {
        if (!visited.contains(vicino)) {
            final_tree.add_edge(node,vicino);
            dfs_function(G, visited, vicino, final_tree);
        }
    }        
}

template<typename T>
unidirected_graph<T> recursive_dfs (unidirected_graph<T>& G, T node) {
    unidirected_graph<T> final_tree;
    std::set<T> visited;

    dfs_function(G, visited, node, final_tree);

    return final_tree;
}
