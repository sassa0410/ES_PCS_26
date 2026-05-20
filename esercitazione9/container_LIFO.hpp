# pragma once
# include <stack>

template<typename T>
class lifo {
    std::stack<T> l;
public:
    void put(T value) {l.push(value);}

    T get() {T value = l.top(); l.pop(); return value;}

    bool empty() const {return l.empty(); }
};
