# pragma once
# include <set>
# include "unidirected_graph.hpp"

template<typename T, typename C>

unidirected_graph<T> graph_visit (const unidirected_graph<T>& G, T node, C& c)
{
    unidirected_graph<T> final_tree;
    std::set<T> visited;

    c.put(node);
    visited.insert(node);

    while(!c.empty()) {
        T visit = c.get();
        for (T vicino : G.neighours(visit)) {
            if (!visited.contains(vicino)) {
                visited.insert(vicino);
                final_tree.add_edge(visit, vicino);
                c.put(vicino);
            }
        }
    }

    return final_tree;
};

