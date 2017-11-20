#include <iostream>
#include <algorithm>

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

bool isBalanced(TN* node, int& height)
{
    if (node == nullptr)
    {
        height = 0;
        return true;
    }

    int leftHeight, rightHeight = 0;
    bool leftBalanced = isBalanced(node->left, leftHeight);
    bool rightBalanced = isBalanced(node->right, rightHeight);
    height = max(leftHeight, rightHeight) + 1;
    return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
}

bool isBalancedBinaryTree(TN* node)
{
    int height = 0;
    return isBalanced(node, height);
}

int main()
{
    TN* root = new TN(0);
    TN* left = new TN(1);
    TN* right = new TN(2);
    TN* leftLeft = new TN(3);
    //root->right = right;
    left->left = leftLeft;
    root->left = left;

    cout << isBalancedBinaryTree(root) << endl;
}