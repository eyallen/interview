#include <iostream>
#include <climits>

using namespace std;

struct TN
{
    int value;
    TN* left;
    TN* right;

    TN(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isBinarySearchTree(TN* root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->value < min || root->value > max)
    {
        return false;
    }

    // NOTE: The below assumes all values unique
    return isBinarySearchTree(root->left, min, root->value -1) &&
           isBinarySearchTree(root->right, root->value +1, max);
}

bool isBinarySearchTree(TN* root)
{
    return isBinarySearchTree(root, INT_MIN, INT_MAX);
}

int main()
{
    TN* root = new TN(10);
    TN* left = new TN(6);
    TN* right = new TN(12);

    TN* ll = new TN(3);
    TN* lr = new TN(9);

    left->left = ll;
    left->right = lr;

    root->left = left;
    root->right = right;

    cout << isBinarySearchTree(root) << endl;
}