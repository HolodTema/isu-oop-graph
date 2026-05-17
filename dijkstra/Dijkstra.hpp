#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "../core/Graph.hpp"
#include "Way.hpp"
#include "WeightMapWrapper.hpp"

class Dijkstra {
private:

	const Graph& graph_;
	const WeightMapWrapper& weightMapWrapper_;

public:

	Dijkstra(const Graph&  graph, const WeightMapWrapper& weightMapWrapper):
		graph_(graph),
		weightMapWrapper_(weightMapWrapper)
	{ }

	Way getShortestWay(Node* begin, Node* end);
};
#endif
