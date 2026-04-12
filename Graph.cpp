#include "Graph.hpp"


void Graph::addNode(Node* node) {
    for (Node::iterator it = node->neighboursBegin(); it != node->neighboursEnd(); it++) {
        (*it)->addNeighbour(node);
    }
    nodes_.insert(node);
}


void Graph::removeNode(Node* node) {
    //remove this node from set of graph nodes
    nodes_.erase(node);

    //for other nodes we need to delete this node from its neighbours
    for (Node::iterator it = nodes_.begin(); it != nodes_.end(); it++) {
        (*it)->removeNeighbour(node);
    }
}


void Graph::addEdge(Node* begin, Node* end) {
    //if there are no begin or end node in the nodes_
    //then we 
    if (nodes_.find(begin) == nodes_.end()) {
        return;
    }
    if (nodes_.find(end) == nodes_.end()) {
        return;
    }

    //bind begin and end nodes
    begin->addNeighbour(end);
    end->addNeighbour(begin);
}


void Graph::removeEdge(Node* begin, Node* end) {
    //if there are no begin or end node in the nodes_
    //then we 
    if (nodes_.find(begin) == nodes_.end()) {
        return;
    }
    if (nodes_.find(end) == nodes_.end()) {
        return;
    }

    //remove binding between end and begin nodes
    begin->removeNeighbour(end);
    end->removeNeighbour(begin);
}


Node::iterator Graph::begin() const {
    return nodes_.begin();
}


Node::iterator Graph::end() const {
    return nodes_.end();
}

