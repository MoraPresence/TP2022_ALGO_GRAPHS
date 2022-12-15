// Copyright 2022 mora

#ifndef GRAPHS_LISTGRAPH_H
#define GRAPHS_LISTGRAPH_H

#include "IGraph.h"


struct ListGraph : public IGraph<size_t> {
public:
    explicit ListGraph(const size_t &size);
    explicit ListGraph(const IGraph &graph);
    void AddEdge(size_t from, size_t to) override;
    [[nodiscard]] size_t VerticesCount() const override;
    [[nodiscard]] std::vector<size_t> GetNextVertices(size_t vertex) const override;
    [[nodiscard]] std::vector<size_t> GetPrevVertices(size_t vertex) const override;

    ~ListGraph() override = default;

private:
    std::vector<std::vector<size_t>> adjacencyLists;
};

ListGraph::ListGraph(const size_t &size)
        : adjacencyLists(size) {
}

ListGraph::ListGraph(const IGraph &graph)
        : adjacencyLists(graph.VerticesCount()) {
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        adjacencyLists[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < adjacencyLists.size());
    assert(to >= 0 && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

size_t ListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

std::vector<size_t> ListGraph::GetNextVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<size_t> ListGraph::GetPrevVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < adjacencyLists.size());
    std::vector<size_t> prevVertices;

    for (size_t from = 0; from < adjacencyLists.size(); ++from) {
        for (auto &to: adjacencyLists[from]) {
            if (to == vertex) {
                prevVertices.push_back(from);
            }
        }
    }

    return prevVertices;
}

#endif //GRAPHS_LISTGRAPH_H
