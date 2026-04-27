#ifndef DFS_HPP
#define DFS_HPP

#include "Graph.hpp"
#include "Node.hpp"

class DFS {
private:

    const Graph& graph_;

    std::set<Node*> setVisited_;

    bool connected(Node* begin, Node* end, int depth);

public:

    explicit DFS(const Graph& graph):
        graph_(graph)
    { }

    bool connected(Node* begin, Node* end);

};
#endif