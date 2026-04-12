#include "Node.hpp"


const std::string& Node::getName() const {
    return name_;
}


Node::iterator Node::neighboursBegin() const {
    return neighbours_.begin();
}


Node::iterator Node::neighboursEnd() const {
    return neighbours_.end();
}


