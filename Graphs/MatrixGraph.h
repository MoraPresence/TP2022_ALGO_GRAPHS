// Copyright 2022 mora

#ifndef GRAPHS_MATRIXGRAPH_H
#define GRAPHS_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph<size_t> {
public:
    explicit MatrixGraph(const size_t &size);
    explicit MatrixGraph(const IGraph &graph);

    void AddEdge(size_t from, size_t to) override;
    [[nodiscard]] size_t VerticesCount() const override;
    [[nodiscard]] std::vector<size_t> GetNextVertices(size_t vertex) const override;
    [[nodiscard]] std::vector<size_t> GetPrevVertices(size_t vertex) const override;

    ~MatrixGraph() override = default;

private:
    std::vector<bool> adjacencyMatrix;
    size_t verticesCount = 0;
};

MatrixGraph::MatrixGraph(const size_t &size) : adjacencyMatrix(size * size), verticesCount(size) {
}

MatrixGraph::MatrixGraph(const IGraph &graph) : adjacencyMatrix(graph.VerticesCount() * graph.VerticesCount()),
                                                verticesCount(graph.VerticesCount()) {
    for (size_t i = 0; i < verticesCount; ++i) {
        for (auto &j: graph.GetNextVertices(i)) {
            adjacencyMatrix[i * verticesCount + j] = true;
        }
    }
}

void MatrixGraph::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < verticesCount);
    assert(to >= 0 && to < verticesCount);
    adjacencyMatrix[from * verticesCount + to] = true;
}

size_t MatrixGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<size_t> MatrixGraph::GetNextVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < verticesCount);
    std::vector<size_t> nextVertices;
    for (size_t i = 0; i < verticesCount; ++i) {
        if (adjacencyMatrix[vertex * verticesCount + i]) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<size_t> MatrixGraph::GetPrevVertices(size_t vertex) const {
    assert(vertex >= 0 && vertex < verticesCount);
    std::vector<size_t> prevVertices;
    for (size_t i = 0; i < verticesCount; i++) {
        if (adjacencyMatrix[i * verticesCount + vertex]) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}

#endif //GRAPHS_MATRIXGRAPH_H
