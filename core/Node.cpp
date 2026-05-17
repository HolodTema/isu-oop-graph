#include "Node.hpp"

void Node::addNeighbour(Node* neighbour) {
    neighbours_.insert(neighbour);
}


void Node::removeNeighbour(Node* neighbour) {
    neighbours_.erase(neighbour);
}


const std::string& Node::getName() const {
    return name_;
}


Node::iterator Node::neighboursBegin() const {
    return neighbours_.begin();
}


Node::iterator Node::neighboursEnd() const {
    return neighbours_.end();
}


