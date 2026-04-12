#include <iostream>
#include "Graph.hpp"


int main() {
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

    graph.addEdge(&node0, &node1);
    graph.addEdge(&node0, &node3);
    graph.addEdge(&node1, &node2);
    graph.addEdge(&node0, &node5);
    graph.addEdge(&node3, &node4);
    graph.addEdge(&node4, &node5);
    graph.addEdge(&node2, &node5);
    



    return 0;
}

