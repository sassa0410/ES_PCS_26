# pragma once
# include <queue>

template<typename T>
class fifo {
std::queue<T> q;

public:
    void put(T value) { q.push(value); }

    T get() { T value = q.front(); q.pop(); return value; }

    bool empty() const { return q.empty();}
};
