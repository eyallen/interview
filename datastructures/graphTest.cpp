#include <iostream>

#include "graph.h"

using namespace datastructures;
using namespace std;

int main()
{
    Node<int>* zero = new Node<int>(0);
    Node<int>* one = new Node<int>(1);
    Node<int>* two = new Node<int>(2);
    Node<int>* three = new Node<int>(3);
    Node<int>* four = new Node<int>(4);
    Node<int>* five = new Node<int>(5);

    /*
     *   0 --> 1 <-- 2
     *   | \   | \   ^
     *   |  \  |  \  |
     *   v   v v   v |
     *   5     4 <-- 3
     */

    zero->Adjacent.push_back(five);
    zero->Adjacent.push_back(four);
    zero->Adjacent.push_back(one);

    one->Adjacent.push_back(four);
    one->Adjacent.push_back(three);

    two->Adjacent.push_back(one);

    three->Adjacent.push_back(two);
    three->Adjacent.push_back(four);

    Graph<int> graph = Graph<int>();
    graph.Nodes = std::vector<Node<int>*>();
    graph.Nodes.push_back(zero);    
    graph.Nodes.push_back(one);
    graph.Nodes.push_back(two);
    graph.Nodes.push_back(three);
    graph.Nodes.push_back(four);
    graph.Nodes.push_back(five);

    //cout << graph.BredthFirstSearch(zero, 6) << endl;
    cout << graph.DepthFirstSearch(zero, 0) << endl;
}