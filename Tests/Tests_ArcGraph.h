// Copyright 2022 mora

#include "help_for_tests.h"

class ArcGraph_Tests : public testing::Test {
protected:
    void SetUp() override {
        graph = new ArcGraph(7);

        graph->AddEdge(0, 1);
        graph->AddEdge(0, 5);
        graph->AddEdge(1, 2);
        graph->AddEdge(1, 3);
        graph->AddEdge(1, 5);
        graph->AddEdge(1, 6);
        graph->AddEdge(3, 2);
        graph->AddEdge(3, 4);
        graph->AddEdge(3, 6);
        graph->AddEdge(5, 4);
        graph->AddEdge(5, 6);
        graph->AddEdge(6, 4);
    }

    void TearDown() override { delete graph; }

    ArcGraph *graph = nullptr;
};

TEST_F(ArcGraph_Tests, BFS_ListGraph) {
    std::vector<size_t> result;
    mainBFS(*graph, [&result](size_t vertex) { result.push_back(vertex); });
    EXPECT_TRUE(result == std::vector<size_t>({0, 1, 5, 2, 3, 6, 4}));
}

TEST_F(ArcGraph_Tests, DFS_ListGraph) {
    std::vector<size_t> result;
    mainDFS(*graph, [&result](size_t vertex) { result.push_back(vertex); });
    EXPECT_TRUE(result == std::vector<size_t>({0, 1, 2, 3, 4, 6, 5}));
}
