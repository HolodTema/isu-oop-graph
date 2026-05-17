#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "../core/Graph.hpp"
#include "Way.hpp"

class Dijkstra {
private:

	const Graph& graph_;

public:

	Dijkstra(const Graph&  graph):
		graph_(graph)
	{ }

	Way getShortestWay(Node* begin, Node* end);
};
#endif
