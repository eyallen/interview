#include <iostream>
#include <queue>

#include "../../datastructures/graph.h"

using namespace datastructures;
using namespace std;

bool pathBetweenNodesExists(Node<int>* root, Node<int>* target)
{
    if (root == nullptr || target == nullptr)
    {
        return false;
    }
    queue<Node<int>*> q = queue<Node<int>*>();
    q.push(root);

    while (!q.empty())
    {
        Node<int>* r = q.front();
        q.pop();

        r->Visited = true;
        if (r == target)
        {
            return true;
        }

        for (size_t i = 0; i < r->Adjacent.size(); ++i)
        {
            if (r->Adjacent[i] != nullptr && !r->Adjacent[i]->Visited)
            {
                q.push(r->Adjacent[i]);
            }
        }
    }

    return false;
}

int main()
{
    Node<int>* one = new Node<int>(1);
    Node<int>* two = new Node<int>(2);
    Node<int>* three = new Node<int>(3);

    one->Adjacent.push_back(two);
    two->Adjacent.push_back(one);
    three->Adjacent.push_back(one);

    cout << pathBetweenNodesExists(three,two) << endl;
}