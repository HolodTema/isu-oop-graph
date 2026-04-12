#ifndef NODE_HPP
#define NODE_HPP

typedef std::set<Node*>::const_iterator node_iterator;


class Node {
private:

    std::string name_;
    
    std::set<Node*> neighbours_;

    void addNeighbour(Node* neighbour);

    void removeNeighbour(Node* neighbour);

    friend class Graph;

public:

    Node(const std::string& name):
        name_(name)
    { }

    const std::string& getName() const;

    node_iterator neighboursBegin() const;

    node_iterator neighboursEnd() const;

};

#endif
