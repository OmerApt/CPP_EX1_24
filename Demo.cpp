
#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main(int argsc, char **agrs)
{
    cout << "begginning demo\n"
         << std::endl;
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);                                       // Load the graph to the object.
    g.printGraph();                                           // Should print: "Graph with 3 vertices and 4 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << ariel::Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    cout << "\n";
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                           // Should print: "Graph with 5 vertices and 8 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << ariel::Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

    cout << "\n";
    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);                                      // Load the graph to the object.
    g.printGraph();                                           // Should print: "Graph with 5 vertices and 10 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << ariel::Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "0->1->2->0" (true).
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

    cout << "\n";
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

    return 0;
}