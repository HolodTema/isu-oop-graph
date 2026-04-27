#include "BFS.hpp"
#include <queue>
#include <set>
#include "Node.hpp"

// goal - determine whether the path between two nodes exists
// BFS = breadth-first-search
bool BFS::connected(Node* begin, Node* end) {
    std::queue<Node*> queueNodes;
    queueNodes.push(begin);

    std::set<Node*> setVisited;

    while (!queueNodes.empty()) {
        Node* nextNode = queueNodes.front();
        queueNodes.pop();

        if (nextNode == end) {
            return true;
        }

        setVisited.insert(nextNode);

        for (Node::iterator it = nextNode->neighboursBegin(); it != nextNode->neighboursEnd(); it++) {
            if (setVisited.find(*it) == setVisited.end()) {
                queueNodes.push(*it);
            }
        }
    }
    return false;
}
