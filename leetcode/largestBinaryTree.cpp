#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findLargestPosition(vector<int> nums, int start, int end)
{
    int largestPos = start;

    for (int i = start; i <= end && i < nums.size(); ++i)
    {
        if (nums[i] > nums[largestPos])
        {
            largestPos = i;
        }
    }

    return largestPos;
}

TreeNode* constructMaxBinaryTree(vector<int> nums, int start, int end)
{
    if (start < 0 || end >= nums.size() || start > end)
    {
        return nullptr;
    }

    int largestPos = findLargestPosition(nums, start, end);
    TreeNode* left = constructMaxBinaryTree(nums, start, largestPos-1);
    TreeNode* right = constructMaxBinaryTree(nums, largestPos+1, end);

    TreeNode* root = new TreeNode(nums[largestPos]);
    root->left = left;
    root->right = right;

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
    return constructMaxBinaryTree(nums, 0, nums.size()-1);
}

void printTree(TreeNode* p, int indent=0)
{
    if (p == nullptr)
    {
        return;
    }

    if(p->right) {
        printTree(p->right, indent+4);
    }
    if (indent) {
        std::cout << std::setw(indent) << ' ';
    }
    if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
    std::cout<< p->val << "\n ";
    if(p->left) {
        std::cout << std::setw(indent) << ' ' <<" \\\n";
        printTree(p->left, indent+4);
    }
}

int main()
{
    vector<int> nums = {3,2,1,6,0,5,10};
    TreeNode* max = constructMaximumBinaryTree(nums);
    printTree(max);
}