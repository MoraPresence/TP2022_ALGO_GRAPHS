// Copyright 2022 mora

#ifndef GRAPHS_ARCGRAPH_H
#define GRAPHS_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph<size_t> {
public:
    explicit ArcGraph(const size_t &size);
    explicit ArcGraph(const IGraph &graph);

    void AddEdge(size_t from, size_t to) override;
    [[nodiscard]] size_t VerticesCount() const override;
    [[nodiscard]] std::vector<size_t> GetNextVertices(size_t vertex) const override;
    [[nodiscard]] std::vector<size_t> GetPrevVertices(size_t vertex) const override;
    ~ArcGraph() override = default;

private:
    std::vector<std::pair<size_t, size_t>> pair_graph;
    size_t verticesCount = 0;
};

ArcGraph::ArcGraph(const size_t &size) : verticesCount(size) {
}

ArcGraph::ArcGraph(const IGraph &graph) : verticesCount(graph.VerticesCount()) {
    for (size_t i = 0; i < verticesCount; ++i) {
        for (auto &adjacent: graph.GetNextVertices(i)) {
            pair_graph.emplace_back(i, adjacent);
        }
    }
}

void ArcGraph::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < verticesCount);
    assert(to >= 0 && to < verticesCount);
    pair_graph.emplace_back(from, to);
}

size_t ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<size_t> ArcGraph::GetNextVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < verticesCount);
    std::vector<size_t> nextVertices;
    for (auto &it: pair_graph) {
        if (it.first == vertex) {
            nextVertices.push_back(it.second);
        }
    }
    return nextVertices;
}

std::vector<size_t> ArcGraph::GetPrevVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < verticesCount);
    std::vector<size_t> prevVertices;
    for (auto &it: pair_graph) {
        if (it.second == vertex) {
            prevVertices.push_back(it.first);
        }
    }
    return prevVertices;
}

#endif //GRAPHS_ARCGRAPH_H
