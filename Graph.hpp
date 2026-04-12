
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iosfwd>

typedef std::set<Node*>::const_iterator node_iterator;


class Graph {
private:
    
    std::set<Node*> nodes_;

public:

    void addNode(Node* node);

    void removeNode(Node* node);

    void addEdge(Node* begin, Node* end);

    void removeEdge(Node* begin, Node* end);

    node_iterator begin() const;

    node_iterator end() const;
};

#endif

