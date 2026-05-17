#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <set>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <iosfwd>
#include "Node.hpp"

class Graph {
private:
    std::set<Node*, NodePtrComparator> nodes_;

public:

    Graph() = default;

    explicit Graph(const std::set<Node*, NodePtrComparator>& setNodes):
        nodes_(setNodes)
    { }

    explicit Graph(const std::string& filename) {
        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            throw std::runtime_error("Cannot open file to create graph.");
        }

        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string nameSource;
        std::string nameTarget;

        while (ifs >> nameSource >> nameTarget) {
            Node* nodeSource = nullptr;
            Node* nodeTarget = nullptr;
            for (auto it = nodes_.begin(); it != nodes_.end(); ++it) {
                if ((*it)->getName() == nameSource) {
                    nodeSource = *it;
                }
                if ((*it)->getName() == nameTarget) {
                    nodeTarget = *it;
                }
                if (nodeSource && nodeTarget) {
                    break;
                }
            }
            if (nodeSource == nullptr) {
                nodeSource = new Node(nameSource);
                nodes_.insert(nodeSource);
            }
            if (nodeTarget == nullptr) {
                nodeTarget = new Node(nameTarget);
                nodes_.insert(nodeTarget);
            }
            addEdge(nodeSource, nodeTarget);
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

