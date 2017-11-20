#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
 * Given a sorted array with unique integer elements, write an algorithm to create a BST
 * with minimal height.
 */
Node* createMinHeightBST(vector<int> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }

    int mid = v.size() / 2;
    Node* root = new Node(v[mid]);
    
    // If we will have a left branch, create it
    if (mid-1 >= 0)
    {
        vector<int> left = vector<int>(&v[0],&v[mid]);
        root->left = createMinHeightBST(left);
    }

    // If we will have a right branch, create it
    if (mid + 1 <= v.size()-1)
    {
        vector<int> right = vector<int>(&v[mid+1],&v[v.size()]);
        root->right = createMinHeightBST(right);
    }

    return root;
}

int main()
{
    vector<int> v = {0,1,2,3,4,5,6};
    Node* tree = createMinHeightBST(v);
}