#include "WeightedOrientedGraph.hpp"
#include <stdexcept>

void WeightedOrientedGraph::addEdge(const Node& nodeFrom, const Node& nodeTo, int weight) {
	std::pair edge(nodeTo, weight);

	if (mapEdges_.find(nodeFrom) == mapEdges_.end()) {
		std::set<std::pair<Node, int>> setEdges;
		setEdges.insert(edge);
		mapEdges_[nodeFrom] = setEdges;
		return;
	}

	if (mapEdges_[nodeFrom].find(edge) != mapEdges_[nodeFrom].end()) {
		throw std::runtime_error("Error: the edge between nodeFrom and nodeTo already exists.");
	}
	mapEdges_[nodeFrom].insert(edge);
}

void WeightedOrientedGraph::removeEdge(const Node& nodeFrom, const Node& nodeTo) {
	if (mapEdges_.find(nodeFrom) == mapEdges_.end()) {
		throw std::runtime_error("Error: you want to delete the edge which does not exist.");
	}

	std::set<std::pair<Node, int>>& setEdges = mapEdges_[nodeFrom];
	for (auto it = setEdges.begin(); it != setEdges.end(); ++it) {
		if (it->first == nodeTo) {
			setEdges.erase(*it);
			return;
		}
	}
	throw std::runtime_error("Error: you want to delete the edge which does not exist.");
}

std::pair<std::vector<Node>, int> WeightedOrientedGraph::getShortestPath(const Node& nodeFrom, const Node& nodeTo) {

}
