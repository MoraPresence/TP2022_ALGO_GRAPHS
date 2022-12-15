// Copyright 2022 mora

#ifndef GRAPHS_IGRAPH_H
#define GRAPHS_IGRAPH_H

#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

template<typename T>
class IGraph{
public:
    virtual ~IGraph() = default;

    virtual void AddEdge(T from, T to) = 0;
    [[nodiscard]] virtual size_t VerticesCount() const  = 0;
    virtual std::vector<T> GetNextVertices(T vertex) const = 0;
    virtual std::vector<T> GetPrevVertices(T vertex) const = 0;
};

#endif //  GRAPHS_IGRAPH_H
