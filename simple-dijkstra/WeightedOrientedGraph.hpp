#ifndef WEIGHTED_ORIENTED_GRAPH_HPP
#define WEIGHTED_ORIENTED_GRAPH_HPP

#include <string>
#include <map>
#include <set>
#include <vector>

struct Node {
	std::string name;

	bool operator<(const Node& other) const {
		return name < other.name;
	}

	bool operator==(const Node& other) const {
		return name == other.name;
	}
};

class WeightedOrientedGraph {
public:

	WeightedOrientedGraph() = default;

	explicit WeightedOrientedGraph(const std::map<Node, std::set<std::pair<Node, int>>>& mapEdges):
		mapEdges_(mapEdges)
	{ }

	void addEdge(const Node& nodeFrom, const Node& nodeTo, int weight);

	void removeEdge(const Node& nodeFrom, const Node& nodeTo);

	std::pair<std::vector<Node>, int> getShortestPath(const Node& nodeFrom, const Node& nodeTo);

private:
	std::map<Node, std::set<std::pair<Node, int>>> mapEdges_;

};

#endif
