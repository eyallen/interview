#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * Assume exactly one solution.
 */
static vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> results;

    // Map where key is number and value is index
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int toFind = target - nums[i];
        if (map.find(toFind) != map.end())
        {
            results.push_back(map[toFind]);
            results.push_back(i);
            break;
        }
        else
        {
            map[nums[i]] = i;
        }
    }

    return results;
}

void printVector(vector<int> v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i != v.size() -1)
        {
            cout << ",";
        }
    }
    cout << "]";
}

int main()
{
    vector<int> test = {2,7,11,15};
    printVector(twoSum(test, 9));
    printVector(twoSum(test, 17));
    printVector(twoSum(test, 26));
    printVector(twoSum(test, 0));
}