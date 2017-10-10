#include <vector>
#include <iostream>

using namespace std;

static vector<int> twoSum(vector<int>& nums, int target)
{
    if (nums.size() < 2)
    {
        return {-1, -1};
    }

    return {-1, -1};
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
    vector<int> test = {0};
    vector<int> result = twoSum(test, 0);
    printVector(result);
}