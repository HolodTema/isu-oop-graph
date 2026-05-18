#ifndef WEIGHT_MAP_WRAPPER_HPP
#define WEIGHT_MAP_WRAPPER_HPP

#include <map>
#include <stdexcept>
#include "../core/Node.hpp"

// struct WeightedEdgeComparator {
//
// 	bool operator()(const std::pair<Node*, Node*>& lhs, const std::pair<Node*, Node*>& rhs) {
//
// 	}
// };

class WeightMapWrapper {
public:

	void setEdgeWeight(Node* node1, Node* node2, int weight) {
		mapWeights_[std::make_pair(node1, node2)] = weight;
	}

	bool hasEdge(Node* node1, Node* node2) const {
		return mapWeights_.find(std::make_pair(node1, node2)) != mapWeights_.end();
	}

	int getEdgeWeight(Node* node1, Node* node2) const {
		std::pair<Node*, Node*> edge = std::make_pair(node1, node2);
		auto it = mapWeights_.find(edge);
		if (it == mapWeights_.end()) {
			throw std::runtime_error("Error: there is no weight of this edge.");
		}
		return it->second;
	}

private:
	std::map<std::pair<Node*, Node*>, int> mapWeights_;

};

#endif