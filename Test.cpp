#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    // undirected unweighted graph
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // undirected unweighted disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test another disconnected graph
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test a single-node graph
    ariel::Graph g5;
    vector<vector<int>> graph5 = {{0}};
    g5.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g5) == true);

    // Test a directed unweighted graph
    vector<vector<int>> directed_unweighted = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(directed_unweighted);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test an undirected weighted graph
    vector<vector<int>> undirected_weighted = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g.loadGraph(undirected_weighted);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test a directed weighted graph
    vector<vector<int>> directed_weighted = {
        {0, 2, 0},
        {0, 0, 3},
        {0, 0, 0}};
    g.loadGraph(directed_weighted);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    // undirected unweighted graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // undirected unweighted disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Test a longer shortest path
    vector<vector<int>> graph3 = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->2->4");

    // Test unreachable nodes
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Test when source and destination nodes are the same
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 1) == "1");

    // Test an undirected weighted graph
    vector<vector<int>> undirected_weighted = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g.loadGraph(undirected_weighted);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Test a directed weighted graph
    vector<vector<int>> directed_weighted = {
        {0, 2, 0},
        {0, 0, 3},
        {0, 0, 0}};
    g.loadGraph(directed_weighted);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    // undirected unweighted graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    // undirected unweighted disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph with a cycle
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test another graph with a cycle
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test an undirected weighted graph with a cycle
    vector<vector<int>> undirected_weighted_with_cycle = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g.loadGraph(undirected_weighted_with_cycle);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a directed weighted graph without a cycle
    vector<vector<int>> directed_weighted_no_cycle = {
        {0, 2, 0},
        {0, 0, 3},
        {0, 0, 0}};
    g.loadGraph(directed_weighted_no_cycle);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test a directed weighted graph with a cycle
    vector<vector<int>> directed_weighted_with_cycle = {
        {0, 2, 0},
        {0, 0, 3},
        {1, 0, 0}};
    g.loadGraph(directed_weighted_with_cycle);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    // undirected unweighted graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    // undirected unweighted disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    // undirected weighted graph
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test a different bipartite graph
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1, 2}");

    // Test a disconnected non-bipartite graph
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test an additional non-bipartite graph
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test an undirected unweighted graph
    vector<vector<int>> undirected_unweighted = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(undirected_unweighted);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Test a directed unweighted graph
    vector<vector<int>> directed_unweighted = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(directed_unweighted);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    // Test invalid input with non-square matrix
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4}};
    CHECK_THROWS(g.loadGraph(graph6));
    // Test invalid input with negative weights
    vector<vector<int>> graph7 = {
        {0, 1, -2},
        {1, 0, 3},
        {-2, 3, 0}};
    CHECK_NOTHROW(g.loadGraph(graph7));
}
