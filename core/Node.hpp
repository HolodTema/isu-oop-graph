#ifndef NODE_HPP
#define NODE_HPP

#include <set>
#include <string>


class Node {
private:

    std::string name_;
    
    std::set<Node*> neighbours_;

    void addNeighbour(Node* neighbour);

    void removeNeighbour(Node* neighbour);


public:
    
    using iterator = std::set<Node*>::const_iterator;

    Node(const std::string& name):
        name_(name)
    { }

    const std::string& getName() const;

    iterator neighboursBegin() const;

    iterator neighboursEnd() const;

    friend class Graph;

};

struct NodePtrComparator {

    bool operator()(const Node* a, const Node* b) const {
        return a->getName() < b->getName();
    }

};


#endif

