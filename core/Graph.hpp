#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <set>
#include <fstream>
#include <limits>
#include <string>
#include <iosfwd>
#include "Node.hpp"


class Graph {
private:
    std::set<Node*> nodes_;

public:

    Graph() = default;

    explicit Graph(const std::string& filename) {
        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            throw std::runtime_error("Cannot open file to create graph.");
        }

        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string source;
        std::string target;
        while (ifs >> source >> target) {
            Node* node = new Node(source);
            bool isNeighbourExist = false;
            for (auto it = nodes_.begin(); it != nodes_.end(); ++it) {
                if ((*it)->getName() == target) {
                    node->addNeighbour(*it);
                    isNeighbourExist = true;
                    break;
                }
            }
            if (!isNeighbourExist) {
                Node* nodeNeighbour = new Node(target);
                node->addNeighbour(nodeNeighbour);
                nodes_.insert(nodeNeighbour);
            }
            nodes_.insert(node);
        }

        ifs.close();
    }

    void addNode(Node* node);

    void removeNode(Node* node);

    void addEdge(Node* begin, Node* end);

    void removeEdge(Node* begin, Node* end);

    Node::iterator begin() const;

    Node::iterator end() const;
};

std::ostream& operator<<(std::ostream& os, const Graph& graph);

#endif

