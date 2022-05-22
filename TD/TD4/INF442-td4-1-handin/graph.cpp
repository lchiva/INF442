#include "graph.hpp" // This is the header for the class implemented here

#include "cloud.hpp" // Used in the constructor
#include "edge.hpp"  // Used in almost all methods

#include <algorithm> // This provides the sort() method for the constructor
#include <cassert>
#include <iostream>
#include <sstream>

/* graph -- method implementations */

graph::graph(const cloud &_c)
{
    n = _c.get_n();
    size = n * (n - 1) / 2;
    // TODO: Exercise 3.1
    edges = new edge *[size];
    node_names = new std::string[n];
    int index = 0;
    for (int point_i = 0; point_i < n; point_i++)
    {
        node_names[point_i] = _c.get_point(point_i).name;
        for (int point_j = point_i + 1; point_j < n; point_j++)
        {
            edges[index] = new edge(point_i, point_j, _c.get_point(point_i).dist(_c.get_point(point_j)));
            index++;
        }
    }
    std::sort(edges, edges + size, edge::compare);
    iterator_pos = 0;
}

graph::graph(long _n, const std::string _node_names[], double **dist_matrix)
{
    n = _n;
    size = n * (n - 1) / 2;
    // TODO: Exercise 3.1
    int index = 0;
    edges = new edge *[size];
    node_names = new std::string[n];
    for (int i = 0; i < n; i++)
    {
        node_names[i] = _node_names[i];
        for (int j = i + 1; j < n; j++)
        {
            edges[index] = new edge(i, j, dist_matrix[i][j]);
            index++;
        }
    }
    std::sort(edges, edges + size, edge::compare);
    iterator_pos = 0;
}

graph::~graph()
{
    // TODO: Exercise 3.1
    for (int i = 0; i < size; i++)
    {
        delete edges[i];
    }
    delete[] edges;
    delete[] node_names;
}

long graph::get_num_edges() const
{
    // TODO: Exercise 3.1
    return size;
}

std::string &graph::get_name(int i) const
{
    assert(i >= 0 && i < n);
    return node_names[i];
}

edge *graph::get_edge(long i)
{
    return edges[i];
}

long graph::get_num_nodes() const
{
    return n;
}

void graph::start_iteration()
{
    // TODO: Exercise 3.2
    iterator_pos = 0;
}

edge *graph::get_next()
{
    // TODO: Exercise 3.2
    if (iterator_pos < size)
        return edges[iterator_pos++];
    return NULL;
}

graph *graph::load_matrix(std::ifstream &is)
{
    assert(is.is_open());

    std::string buffer;
    getline(is, buffer, '\n');
    int n = std::stoi(buffer);
    std::string node_names[n];
    for (size_t i = 0; i < n; ++i)
    {
        getline(is, node_names[i], '\n');
    }

    std::cout << "Names read" << std::endl;
    double **dist_matrix = new double *[n];
    for (int i = 0; i < n; ++i)
    {
        dist_matrix[i] = new double[n];
        std::getline(is, buffer, '\n');
        std::stringstream ls;
        ls << buffer;
        std::string dist_str;
        for (int j = 0; j < n; ++j)
        {
            std::getline(ls, dist_str, ',');
            dist_matrix[i][j] = std::stod(dist_str);
        }
    }

    graph *g = new graph(n, node_names, dist_matrix);
    for (size_t i = 0; i < n; ++i)
    {
        delete[] dist_matrix[i];
    }
    delete[] dist_matrix;

    return g;
}
