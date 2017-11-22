#include <iostream>

using namespace std;

struct TN
{
    int value;
    TN* left;
    TN* right;
    TN* parent;

    TN(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

TN* getLeftmostNode(TN* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TN* left = root;
    while (left->left != nullptr)
    {
        left = left->left;
    }

    return left;
}

TN* getSuccessor(TN* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    // If we have a right node, then we just need to get the leftmost node
    // of the right subtree
    if (root->right != nullptr)
    {
        return getLeftmostNode(root->right);
    }

    // If not, we have already traversed this subtree and we need to find the parent
    // that contains this node in it's left subtree.
    TN* n = root;
    TN* p = root->parent;
    while (p != nullptr && p->left != n)
    {
        n = p;
        p = n->parent;
    }

    // This will either be the parent of the left subtree, or null if we are on the last node
    return p;
}

int main()
{
    TN* one = new TN(1);
    TN* two = new TN(2);
    TN* three = new TN(3);
    TN* four = new TN(4);
    TN* five = new TN(5);
    TN* six = new TN(6);
    TN* seven = new TN(7);

    four->left = two;
    four->right = six;

    two->left = one;
    two->right = three;
    two->parent = four;

    one->parent = two;
    three->parent = two;

    six->left = five;
    six->right = seven;
    six->parent = four;

    five->parent = six;
    seven->parent = six;

    cout << getSuccessor(one)->value << endl;
    cout << getSuccessor(two)->value << endl;
    cout << getSuccessor(three)->value << endl;
    cout << getSuccessor(four)->value << endl;
    cout << getSuccessor(five)->value << endl;
    cout << getSuccessor(six)->value << endl;
}