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
	queueNodes.push(MarkedNode(begin, 0, nullptr));

	std::map<Node*, MarkedNode> mapVisited;

	while (!queueNodes.isEmpty()) {
		MarkedNode nextMarkedNode = queueNodes.pop();
		if (mapVisited.find(nextMarkedNode.node) != mapVisited.end()) {
			continue;
		}
		mapVisited[nextMarkedNode.node] = nextMarkedNode;

		if (end == nextMarkedNode.node) {
			return unroll(mapVisited, begin, end);
		}

		for (auto it = nextMarkedNode.node->neighboursBegin(); it != nextMarkedNode.node->neighboursEnd(); ++it) {
			Node* neighbourNode = *it;

			if (!weightMapWrapper_.hasEdge(nextMarkedNode.node, neighbourNode)) {
				continue;
			}
			if (mapVisited.find(neighbourNode) != mapVisited.end()) {
				continue;
			}

			int newDistance = weightMapWrapper_.getEdgeWeight(nextMarkedNode.node, neighbourNode) + nextMarkedNode.mark;
			queueNodes.push(MarkedNode(neighbourNode, newDistance, nextMarkedNode.node));
		}
	}
	return Way();
}
