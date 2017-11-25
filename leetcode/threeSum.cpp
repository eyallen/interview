#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <algorithm>

using namespace std;

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 */
vector<vector<int> > threeSum(vector<int>& nums) 
{
    vector<vector<int> > pairs = vector<vector<int> >();
    if (nums.size() < 3)
    {
        return pairs;
    }

    // Sort the array to help identify unique elements
    sort(nums.begin(), nums.end());

    // The elements we have already seen stored in an unordered_set for constant time lookup
    auto haveSeen = unordered_set<int>();
    for(size_t i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            auto toFind = (nums[i] + nums[j]) * -1;
            if (haveSeen.find(toFind) != haveSeen.end())
            {
                vector<int> vec = {nums[i],nums[j],toFind};
                pairs.push_back(vec);
            }
        }

        haveSeen.insert(nums[i]);
    }

    return pairs;
}

int main()
{
    vector<int> s = {-1, 0, 1, 2, -1, -4};
    auto pairs = threeSum(s);
}