#ifndef MARKED_NODE_HPP
#define MARKED_NODE_HPP

#include "../core/Node.hpp"

class MarkedNode {
public:
	Node *node;
	int mark;
	Node *prevNode;

	MarkedNode(Node *node = 0, int mark = 0, Node *prevNode = 0):
		node(node),
        mark(mark),
        prevNode(prevNode)
	{ }
};

#endif
