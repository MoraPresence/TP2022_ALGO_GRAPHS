// Copyright 2022 mora

#include "help_for_tests.h"

class GraphConstructors_Tests : public testing::Test {
protected:
    void SetUp() override {
        arc_graph = new ArcGraph(7);
        arc_graph->AddEdge(0, 1);
        arc_graph->AddEdge(0, 5);
        arc_graph->AddEdge(1, 2);
        arc_graph->AddEdge(1, 3);
        arc_graph->AddEdge(1, 5);
        arc_graph->AddEdge(1, 6);
        arc_graph->AddEdge(3, 2);
        arc_graph->AddEdge(3, 4);
        arc_graph->AddEdge(3, 6);
        arc_graph->AddEdge(5, 4);
        arc_graph->AddEdge(5, 6);
        arc_graph->AddEdge(6, 4);

        list_graph = new ListGraph(7);
        list_graph->AddEdge(0, 1);
        list_graph->AddEdge(0, 5);
        list_graph->AddEdge(1, 2);
        list_graph->AddEdge(1, 3);
        list_graph->AddEdge(1, 5);
        list_graph->AddEdge(1, 6);
        list_graph->AddEdge(3, 2);
        list_graph->AddEdge(3, 4);
        list_graph->AddEdge(3, 6);
        list_graph->AddEdge(5, 4);
        list_graph->AddEdge(5, 6);
        list_graph->AddEdge(6, 4);

        matrix_graph = new MatrixGraph(7);
        matrix_graph->AddEdge(0, 1);
        matrix_graph->AddEdge(0, 5);
        matrix_graph->AddEdge(1, 2);
        matrix_graph->AddEdge(1, 3);
        matrix_graph->AddEdge(1, 5);
        matrix_graph->AddEdge(1, 6);
        matrix_graph->AddEdge(3, 2);
        matrix_graph->AddEdge(3, 4);
        matrix_graph->AddEdge(3, 6);
        matrix_graph->AddEdge(5, 4);
        matrix_graph->AddEdge(5, 6);
        matrix_graph->AddEdge(6, 4);

        set_graph = new SetGraph(7);
        set_graph->AddEdge(0, 1);
        set_graph->AddEdge(0, 5);
        set_graph->AddEdge(1, 2);
        set_graph->AddEdge(1, 3);
        set_graph->AddEdge(1, 5);
        set_graph->AddEdge(1, 6);
        set_graph->AddEdge(3, 2);
        set_graph->AddEdge(3, 4);
        set_graph->AddEdge(3, 6);
        set_graph->AddEdge(5, 4);
        set_graph->AddEdge(5, 6);
        set_graph->AddEdge(6, 4);

        mainBFS(*arc_graph,
                [this](size_t vertex) { BFS_arc_graph.push_back(vertex); });

        mainBFS(*list_graph,
                [this](size_t vertex) { BFS_list_graph.push_back(vertex); });

        mainBFS(*matrix_graph,
                [this](size_t vertex) { BFS_matrix_graph.push_back(vertex); });

        mainBFS(*set_graph,
                [this](size_t vertex) { BFS_set_graph.push_back(vertex); });

    }

    void TearDown() override {
        delete arc_graph;
        delete list_graph;
        delete matrix_graph;
        delete set_graph;
    }

    ArcGraph *arc_graph = nullptr;
    ListGraph *list_graph = nullptr;
    MatrixGraph *matrix_graph = nullptr;
    SetGraph *set_graph = nullptr;

    std::vector<size_t> BFS_arc_graph;
    std::vector<size_t> BFS_list_graph;
    std::vector<size_t> BFS_matrix_graph;
    std::vector<size_t> BFS_set_graph;
};

TEST_F(GraphConstructors_Tests, ArcGraph_to_ListGraph) {
    ListGraph new_list_graph(*arc_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_list_graph);
}

TEST_F(GraphConstructors_Tests, ArcGraph_to_MatrixGraph) {
    MatrixGraph new_list_graph(*arc_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_matrix_graph);
}

TEST_F(GraphConstructors_Tests, ArcGraph_to_SetGraph) {
    SetGraph new_list_graph(*arc_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_set_graph);
}

TEST_F(GraphConstructors_Tests, ListGraph_to_ArcGraph) {
    ArcGraph new_list_graph(*list_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_arc_graph);
}

TEST_F(GraphConstructors_Tests, ListGraph_to_MatrixGraph) {
    MatrixGraph new_list_graph(*list_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_matrix_graph);
}

TEST_F(GraphConstructors_Tests, ListGraph_to_SetGraph) {
    SetGraph new_list_graph(*list_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_set_graph);
}

TEST_F(GraphConstructors_Tests, MatrixGraph_to_ArcGraph) {
    ArcGraph new_list_graph(*matrix_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_arc_graph);
}

TEST_F(GraphConstructors_Tests, MatrixGraph_to_ListGraph) {
    ListGraph new_list_graph(*matrix_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_list_graph);
}

TEST_F(GraphConstructors_Tests, MatrixGraph_to_SetGraph) {
    SetGraph new_list_graph(*matrix_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_set_graph);
}

TEST_F(GraphConstructors_Tests, SetGraph_to_ArcGraph) {
    ArcGraph new_list_graph(*set_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_arc_graph);
}

TEST_F(GraphConstructors_Tests, SetGraph_to_ListGraph) {
    ListGraph new_list_graph(*set_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_list_graph);
}

TEST_F(GraphConstructors_Tests, SetGraph_to_SetGraph) {
    MatrixGraph new_list_graph(*set_graph);

    std::vector<size_t> result;
    mainBFS(new_list_graph,
            [&result](size_t vertex) { result.push_back(vertex); });

    EXPECT_TRUE(result == BFS_matrix_graph);
}
