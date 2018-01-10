#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) 
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void printTree(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);

    four->left = two;
    four->right = seven;

    two->left = one;
    two->right = three;

    seven->left = six;
    seven->right = five;

    printTree(four);

    cout << " ---- " << endl;
    invertTree(four);

    printTree(four);
}