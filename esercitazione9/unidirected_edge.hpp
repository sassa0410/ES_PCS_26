# pragma once

# include <iostream>


template <typename T>
class unidirected_edge {
    T n_from;
    T n_to;

public:
    /*  Costruttore di user-defined  */
    unidirected_edge(T a, T b) {
        if (a < b) {
            n_from = a;
            n_to = b;
        }
        else {
            n_from = b;
            n_to = a;
        }
    }


    /*  Restituiscono i nodi estremi dell'arco */
    T from() const { return n_from; }
    T to() const { return n_to; }


    /*  Operator <  */
    bool operator<(const unidirected_edge& other) const {
        if (n_from == other.n_from) {
            return n_to < other.n_to;
        }
        return n_from < other.n_from;
    }


    /*  Operator ==  */
    bool operator==(const unidirected_edge& other) const {
        return (n_from==other.n_from) && (n_to == other.n_to);
    }

};


    /*  Operator <<  */
template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& e) {
    os << "( " << e.from() << " , " << e.to() << " )";
    return os;
};
