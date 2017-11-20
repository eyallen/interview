#include <iostream>
#include <vector>
#include <queue>

namespace datastructures 
{

template<class T>
struct Node
{
    T Value;
    bool Visited;
    std::vector<Node<T>*> Adjacent;

    Node(T val)
    {
        Adjacent = std::vector<Node<T>*>();
        Visited = false;
        Value = val;
    }
};

template<class T>
class Graph
{
public:
    std::vector<Node<T>*> Nodes;

    bool BredthFirstSearch(Node<T>* root, T item)
    {
        std::queue<Node<T>*> q = std::queue<Node<T>*>();
        root->Visited = true;
        q.push(root);

        while(!q.empty())
        {
            Node<T>* r = q.front();
            q.pop();
            if (r->Value == item)
            {
                return true;
            }
            
            for (int i = 0; i < r->Adjacent.size(); ++i)
            {
                Node<T>* n = r->Adjacent[i];
                if (!n->Visited)
                {
                    n->Visited = true;
                    q.push(n);
                }
            }
        }

        return false;
    }

    bool DepthFirstSearch(Node<T>* root, T item)
    {
        if (root == nullptr)
        {
            return false;
        }
        
        root->Visited = true;
        if (root->Value == item)
        {
            return true;
        }

        for (int i = 0; i < root->Adjacent.size(); ++i)
        {
            if (!root->Adjacent[i]->Visited)
            {
                if (DepthFirstSearch(root->Adjacent[i], item))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

}