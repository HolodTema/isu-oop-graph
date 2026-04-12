#include "Node.hpp"


const std::string& Node::getName() const {
    return name_;
}


node_iterator Node::neighboursBegin() const {
    return neighbours_.begin();
}


node_iterator Node::neighboursEnd() const {
    return neighbours_.end();
}


