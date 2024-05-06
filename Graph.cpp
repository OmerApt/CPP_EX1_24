#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Graph.hpp"

using namespace std;
namespace ariel
{
    void Graph::loadGraph(vector<vector<int>> g)
    {
       unsigned int rows = g.size();
        for (unsigned int i = 0; i < rows; i++)
        {
            if (rows != g[i].size())
            {
                throw std::out_of_range{"Invalid graph: The graph is not a square matrix."};
            }
        }
        this->nodes_num = rows;
        this->actual_graph = (int *)malloc(rows * rows * sizeof(int));
        if (this->actual_graph != NULL)
        {
            for (unsigned int r = 0; r < rows; r++)
            {
                for (unsigned int c = 0; c < rows; c++)
                {
                    int edge = g[r].at(c);
                    this->num_edges += (edge != 0) ? 1 : 0;
                    this->setedge(r, c, edge);
                }
            }
        }
    }

    void Graph::setedge(unsigned int a, unsigned int b, int value)
    {
        // need to check if parameters in range for safer code
        this->actual_graph[this->nodes_num * a + b] = value;
    }

    int Graph::getedge(unsigned int row, unsigned int collumn)
    {
        // need to check if parameters in range for safer code
        return this->actual_graph[this->nodes_num * row + collumn];
    }

    void Graph::printGraph()
    {
        cout << "Graph with " << this->nodes_num << " vertices and " << this->num_edges << " edges";
    }

    Graph::~Graph()
    {
        if (this->actual_graph != 0)
            free(this->actual_graph);
    }
}