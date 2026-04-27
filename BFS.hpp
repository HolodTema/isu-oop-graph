#ifndef BFS_H
#define BFS_H

#include "Graph.hpp"

class BFS {
private:

    const Graph& graph_;

public:

    explicit BFS(const Graph& graph):
        graph_(graph)
    { }

    bool connected(Node* begin, Node* end);

};

#endif
