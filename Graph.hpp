#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <set>
#include "Node.hpp"


class Graph {
private:
    
    std::set<Node*> nodes_;

public:

    void addNode(Node* node);

    void removeNode(Node* node);

    void addEdge(Node* begin, Node* end);

    void removeEdge(Node* begin, Node* end);

    Node::iterator begin() const;

    Node::iterator end() const;
};

#endif

