#include <vector>
#pragma once

namespace ariel
{
    class Graph
    {
    private:
        // number of nodes
        unsigned int nodes_num;
        // number of edges
        unsigned int num_edges;
        // use 1d array to represent matrice
        int *actual_graph;
        // for initilazing graph
        void setedge(unsigned int a, unsigned int b, int value);

    public:
        Graph()
        {
            this->actual_graph = 0;
            this->nodes_num = 0;
            this->num_edges = 0;
        };
        ~Graph();
        void loadGraph(std::vector<std::vector<int>> g);
        void printGraph();
        // return the edge from a to b if exists else return 0
        int getedge(unsigned int row, unsigned int collumn);
        unsigned int get_num_of_nodes()
        {
            return this->nodes_num;
        }
    };

} // namespace ariel
