#include <iostream>

#include "bfs/BFS.hpp"
#include "core/Graph.hpp"

void testBFS() {
    std::cout << "Test BFS algorithm:\n";
    Node node0("0");
    Node node1("1");
    Node node2("2");
    Node node3("3");
    Node node4("4");
    Node node5("5");

    Graph graph;
    graph.addNode(&node0);
    graph.addNode(&node1);
    graph.addNode(&node2);
    graph.addNode(&node3);
    graph.addNode(&node4);
    graph.addNode(&node5);

    graph.addEdge(&node0, &node3);
    graph.addEdge(&node1, &node2);
    graph.addEdge(&node0, &node5);
    graph.addEdge(&node3, &node4);
    graph.addEdge(&node4, &node5);

    std::cout << "Created graph (disconnected in two subgraphs 1,2 and 0,3,4,5):\n" << graph << "\n";
    BFS bfs(graph);
    std::cout << "Have way between 0 and 0 (expected true):\t" << bfs.connected(&node0, &node0) << "\n";
    std::cout << "Have way between 0 and 1 (expected false):\t" << bfs.connected(&node0, &node1) << "\n";
    std::cout << "Have way between 0 and 2 (expected false):\t" << bfs.connected(&node0, &node2) << "\n";
    std::cout << "Have way between 0 and 3 (expected true):\t" << bfs.connected(&node0, &node3) << "\n";
    std::cout << "Have way between 0 and 4 (expected true):\t" << bfs.connected(&node0, &node4) << "\n";
    std::cout << "Have way between 0 and 5 (expected true):\t" << bfs.connected(&node0, &node5) << "\n";
    std::cout << "\n";
    std::cout << "Have way between 1 and 0 (expected false):\t" << bfs.connected(&node1, &node0) << "\n";
    std::cout << "Have way between 1 and 1 (expected true):\t" << bfs.connected(&node1, &node1) << "\n";
    std::cout << "Have way between 1 and 2 (expected true):\t" << bfs.connected(&node1, &node2) << "\n";
    std::cout << "Have way between 1 and 3 (expected false):\t" << bfs.connected(&node1, &node3) << "\n";
    std::cout << "Have way between 1 and 4 (expected false):\t" << bfs.connected(&node1, &node4) << "\n";
    std::cout << "Have way between 1 and 5 (expected false):\t" << bfs.connected(&node1, &node5) << "\n";
    std::cout << "\n";
    std::cout << "Have way between 2 and 0 (expected false):\t" << bfs.connected(&node2, &node0) << "\n";
    std::cout << "Have way between 2 and 1 (expected true):\t" << bfs.connected(&node2, &node1) << "\n";
    std::cout << "Have way between 2 and 2 (expected true):\t" << bfs.connected(&node2, &node2) << "\n";
    std::cout << "Have way between 2 and 3 (expected false):\t" << bfs.connected(&node2, &node3) << "\n";
    std::cout << "Have way between 2 and 4 (expected false):\t" << bfs.connected(&node2, &node4) << "\n";
    std::cout << "Have way between 2 and 5 (expected false):\t" << bfs.connected(&node2, &node5) << "\n";
    std::cout << "\n";
    std::cout << "Have way between 3 and 0 (expected true):\t" << bfs.connected(&node3, &node0) << "\n";
    std::cout << "Have way between 3 and 1 (expected false):\t" << bfs.connected(&node3, &node1) << "\n";
    std::cout << "Have way between 3 and 2 (expected false):\t" << bfs.connected(&node3, &node2) << "\n";
    std::cout << "Have way between 3 and 3 (expected true):\t" << bfs.connected(&node3, &node3) << "\n";
    std::cout << "Have way between 3 and 4 (expected true):\t" << bfs.connected(&node3, &node4) << "\n";
    std::cout << "Have way between 3 and 5 (expected true):\t" << bfs.connected(&node3, &node5) << "\n";
    std::cout << "\n";
    std::cout << "Have way between 4 and 0 (expected true):\t" << bfs.connected(&node4, &node0) << "\n";
    std::cout << "Have way between 4 and 1 (expected false):\t" << bfs.connected(&node4, &node1) << "\n";
    std::cout << "Have way between 4 and 2 (expected false):\t" << bfs.connected(&node4, &node2) << "\n";
    std::cout << "Have way between 4 and 3 (expected true):\t" << bfs.connected(&node4, &node3) << "\n";
    std::cout << "Have way between 4 and 4 (expected true):\t" << bfs.connected(&node4, &node4) << "\n";
    std::cout << "Have way between 4 and 5 (expected true):\t" << bfs.connected(&node4, &node5) << "\n";
    std::cout << "\n";
    std::cout << "Have way between 5 and 0 (expected true):\t" << bfs.connected(&node5, &node0) << "\n";
    std::cout << "Have way between 5 and 1 (expected false):\t" << bfs.connected(&node5, &node1) << "\n";
    std::cout << "Have way between 5 and 2 (expected false):\t" << bfs.connected(&node5, &node2) << "\n";
    std::cout << "Have way between 5 and 3 (expected true):\t" << bfs.connected(&node5, &node3) << "\n";
    std::cout << "Have way between 5 and 4 (expected true):\t" << bfs.connected(&node5, &node4) << "\n";
    std::cout << "Have way between 5 and 5 (expected true):\t" << bfs.connected(&node5, &node5) << "\n";
}

void testBfsFromFile() {
    Graph graph("./assets/testgraph.txt");
    std::cout << "Graph from file testgraph.txt:\n";
    std::cout << graph << "\n";

    BFS bfs(graph);
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        for (auto it2 = graph.begin(); it2 != graph.end(); ++it2) {
            std::cout << "Have way between " << (*it)->getName() << " and " << (*it2)->getName() << ":\t" << bfs.connected(*it, *it2) << "\n";
        }
        std::cout << "\n";
    }
}

void splitGraphIntoSubgraphsInFiles(const Graph& graph) {
    BFS bfs(graph);

    std::vector<Node*> vecAllNodes;
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        vecAllNodes.push_back(*it);
    }

    int subgraphNumber = 0;
    std::set<Node*, NodePtrComparator> setVisitedNodes;
    for (Node* startNode : vecAllNodes) {
        if (setVisitedNodes.find(startNode) != setVisitedNodes.end()) {
            continue;
        }

        std::set<Node*, NodePtrComparator> setNodesConnectedToStartNode;
        for (Node* node : vecAllNodes) {
            if (setVisitedNodes.find(node) == setVisitedNodes.end()) {
                if (bfs.connected(startNode, node)) {
                    setNodesConnectedToStartNode.insert(node);
                    setVisitedNodes.insert(node);
                }
            }
        }

        std::string filename = "./out/subgraph" + std::to_string(subgraphNumber) + ".txt";
        std::ofstream ofs(filename);
        Graph subgraph(setNodesConnectedToStartNode);
        ofs << subgraph;
        subgraphNumber++;
    }
}

int main() {
    splitGraphIntoSubgraphsInFiles(Graph("./assets/testgraph.txt"));
    return 0;
}

