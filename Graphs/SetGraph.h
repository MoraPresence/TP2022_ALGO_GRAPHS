// Copyright 2022 mora

#ifndef GRAPHS_SETGRAPH_H
#define GRAPHS_SETGRAPH_H

#include "IGraph.h"

#include <unordered_set>

class SetGraph : public IGraph<size_t> {
public:
    explicit SetGraph(const size_t &size);

    explicit SetGraph(const IGraph &graph);

    void AddEdge(size_t from, size_t to) override;

    [[nodiscard]] size_t VerticesCount() const override;

    [[nodiscard]] std::vector<size_t> GetNextVertices(size_t vertex) const override;

    [[nodiscard]] std::vector<size_t> GetPrevVertices(size_t vertex) const override;

    ~SetGraph() override = default;

private:
    std::vector<std::unordered_set<size_t>> hashTable_graph;
};

SetGraph::SetGraph(const size_t &size) : hashTable_graph(size) {
}

SetGraph::SetGraph(const IGraph &graph) : hashTable_graph(graph.VerticesCount()) {
    for (size_t i = 0; i < hashTable_graph.size(); ++i) {
        for (auto &j: graph.GetNextVertices(i)) {
            hashTable_graph[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(size_t from, size_t to) {
    hashTable_graph[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return hashTable_graph.size();
}

std::vector<size_t> SetGraph::GetNextVertices(size_t vertex) const {
    return {hashTable_graph[vertex].begin(), hashTable_graph[vertex].end()};
}

std::vector<size_t> SetGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prevVertices;
    for (size_t iter_vertex = 0; iter_vertex < hashTable_graph.size(); iter_vertex++) {
        if (hashTable_graph[iter_vertex].find(vertex) != hashTable_graph[iter_vertex].end()) {
            prevVertices.push_back(iter_vertex);
        }
    }
    return prevVertices;
}

#endif //GRAPHS_SETGRAPH_H
