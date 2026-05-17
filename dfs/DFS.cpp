#include "../DFS.hpp"

bool DFS::connected(Node* begin, Node* end) {
	setVisited_.clear();
	return connected(begin, end, 0);
}

bool DFS::connected(Node* begin, Node* end, int depth) {
	if (begin == end) {
		return true;
	}

	setVisited_.insert(begin);

	for (Node::iterator it = begin->neighboursBegin(); it != begin->neighboursEnd(); ++it) {
		if (setVisited_.find(*it) == setVisited_.end()) {
			if (connected(*it, end, depth + 1)) {
				return true;
			}
		}
	}
	return false;
}