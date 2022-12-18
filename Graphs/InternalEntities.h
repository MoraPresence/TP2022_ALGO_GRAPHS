// Copyright 2022 mora

#ifndef GRAPHS_INTERNALENTITIES_H
#define GRAPHS_INTERNALENTITIES_H


#include "IGraph.h"

template<typename T>
void BFS(const IGraph<T> &graph, size_t vertex, std::vector<bool> &visited, const std::function<void(T)> &func) {
    std::queue<T> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        auto currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (auto nextVertex: graph.GetNextVertices(currentVertex)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

template<typename T>
void mainBFS(const IGraph<T> &graph, const std::function<void(size_t)> &func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, func);
        }
    }
}

template<typename T>
void DFS(const IGraph<T> &graph, size_t vertex, std::vector<bool> &visited, const std::function<void(size_t)> &func) {
    visited[vertex] = true;
    func(vertex);

    for (auto nextVertex: graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, func);
    }
}

template<typename T>
void mainDFS(const IGraph<T> &graph, const std::function<void(size_t)> &func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, func);
        }
    }
}

template<typename T>
void topologicalSortInternal(const IGraph<T> &graph, size_t vertex, std::vector<bool> &visited, std::deque<size_t> &sorted) {
    visited[vertex] = true;

    for (auto nextVertex: graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            topologicalSortInternal(graph, nextVertex, visited, sorted);
        }
    }

    sorted.push_front(vertex);
}

template<typename T>
std::deque<T> topologicalSort(const IGraph<T> &graph) {
    std::deque<T> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            topologicalSortInternal(graph, i, visited, sorted);
        }
    }

    return sorted;
}

#endif //GRAPHS_INTERNALENTITIES_H
