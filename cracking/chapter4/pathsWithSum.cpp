#include <iostream>
#include <unordered_map>

using namespace std;

struct TN
{
    TN* left = nullptr;
    TN* right = nullptr;

    int value;

    TN(int val) :
        value(val)
    {}
};

/*
 *          1
 *        2   1
 *      -1 0 1 1
 * 
 * val = 3, ret = 4
 * 
 * 
 * 1, [-1,0] [2,1,2], 1,3,2,3
 */

void incrementHash(unordered_map<int,int>& pathCount, int currentCount, int delta)
{
    if (pathCount.find(currentCount) != pathCount.end())
    {
        pathCount[currentCount] += delta;
    }
    else
    {
        pathCount[currentCount] = delta;
    }
}

int searchPaths(TN* node, int value, int currentCount, unordered_map<int,int>& pathCount)
{
    if (node == nullptr)
    {
        return 0;
    }

    currentCount += node->value;
    int count = currentCount - value;
    
    int totalPaths = 0;
    if (pathCount.find(count) != pathCount.end())
    {
        totalPaths = pathCount[count];
    }

    if (currentCount == value)
    {
        totalPaths++;
    }

    incrementHash(pathCount, currentCount, 1);
    totalPaths += searchPaths(node->left, value, currentCount, pathCount);
    totalPaths += searchPaths(node->right, value, currentCount, pathCount);
    incrementHash(pathCount, currentCount, -1);

    return totalPaths;
}

/*
 * You are given a binary tree in which each node contains an integer value (positive or negative).
 * Design an alorithm to count the number of paths that sum to a given value. The path does not need
 * to start or end at the root or a leaf, but it must go downwards.
 */
int pathsToSum(TN* tree, int value)
{
    unordered_map<int,int> pathCount = unordered_map<int,int>();
    return searchPaths(tree, value, 0, pathCount);
}

int main()
{
    TN* root = new TN(1);
    TN* l = new TN(2);
    TN* r = new TN(1);
    TN* ll = new TN(-1);
    TN* lr = new TN(0);
    TN* rl = new TN(1);
    TN* rr = new TN(1);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    r->left = rl;
    r->right = rr;

    cout << pathsToSum(root, 3) << endl;
    cout << pathsToSum(root, 2) << endl;
}