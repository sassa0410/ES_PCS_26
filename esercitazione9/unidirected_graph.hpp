# pragma once

# include <iostream>
# include <set>
# include <map>
# include "unidirected_edge.hpp"
# include <fstream>


template <typename T>
class unidirected_graph {
    std::set<T> nodes;
    std::map<T, std::set<T>> adj_map;

    int edge_counter;
    std::map<unidirected_edge<T>, int> edge_to_id;
    std::map<int, unidirected_edge<T>> id_to_edge;

public:
    /*  Costruttore di default  */
    unidirected_graph()
        : edge_counter(0)
    {}

    /*  Costruttore di copia  */
    unidirected_graph(const unidirected_graph& other)=default;

    /*  Metodo di neighbours  */
    std::set<T> neighours(T node) const {
        if (adj_map.contains(node)) {
            return adj_map.at(node);
        }
        return {};
    }

    /*  Metodo add edge  */
    void add_edge(T u, T v) {
        unidirected_edge<T> edge(u, v);
        nodes.insert(u);
        nodes.insert(v);
        adj_map[v].insert(u);
        adj_map[u].insert(v);
        if (!edge_to_id.contains(edge)) {
            edge_to_id[edge]=edge_counter;
            id_to_edge.insert({edge_counter,edge});
            edge_counter++;
        }
    }

    /*  Metodo all edges  */
    std::set<unidirected_edge<T>> all_edges() const {
        std::set<unidirected_edge<T>> edges;
        for (const auto& [key, value] : edge_to_id) {
            edges.insert(key);
        }
        return edges;
    }

    /*  Metodo all nodes  */ 
    std::set<T> all_nodes() const {
        return nodes;
    }

    /*  Metodo edge_number  */
    int edge_number(const unidirected_edge<T>& e) const {
        if (edge_to_id.contains(e)) {
            return edge_to_id.at(e);
        }
        return -1;
    }

    /*  Metodo edge_at */
    unidirected_edge<T> edge_at(int num) const {
        return id_to_edge.at(num);
    }

    /*  Operator-  */ 
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& [key, value] : edge_to_id) {
            if (!other.edge_to_id.contains(key)) {
                result.add_edge(key.from(), key.to());
            }
        }
        return result;
    }


    void save_to_dot(const std::string& filename) const {
        std::ofstream file(filename);
        file << "graph G {\n";
    
        for (const auto& edge : all_edges()) {
            file << "   " << edge.from() << " -- " << edge.to() << ";\n";
        }
        file << "}\n";
        }
};
