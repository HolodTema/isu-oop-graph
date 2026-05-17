#include "Dijkstra.hpp"
#include <map>
#include "PriorityQueue.hpp"
#include "MarkedNode.hpp"
#include "WeightMapWrapper.hpp"

static Way unroll(std::map<Node*, MarkedNode>& mapVisited, Node* begin, Node* curr) {
	Way way;
	way.length = mapVisited[curr].mark;
	while (curr != begin) {
		way.vecNodes.push_back(curr);
		curr = mapVisited[curr].prevNode;
	}
	way.vecNodes.push_back(begin);
	return way;
}

Way Dijkstra::getShortestWay(Node *begin, Node *end) {
	PriorityQueue<MarkedNode> queueNodes;
	queueNodes.push(MarkedNode(begin, 0, 0));

	std::map<Node*, MarkedNode> mapVisited;

	while (!queueNodes.isEmpty()) {
		MarkedNode nextMarkedNode = queueNodes.pop();
		mapVisited[nextMarkedNode.node] = nextMarkedNode;

		if (end == nextMarkedNode.node) {
			return unroll(mapVisited, begin, end);
		}

		for (auto it = nextMarkedNode.node->neighboursBegin(); it != nextMarkedNode.node->neighboursEnd(); ++it) {
			int weight = weightMapWrapper_.getEdgeWeight(nextMarkedNode.node, *it) + nextMarkedNode.mark;
			if (mapVisited.find(*it) == mapVisited.end()) {
				queueNodes.push(MarkedNode(*it, weight, nextMarkedNode.node));
			}
		}
	}
	return Way();
}
