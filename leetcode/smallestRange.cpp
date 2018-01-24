#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct range_t
{
    int min = INT_MIN;
    int max = INT_MAX;

    range_t(int minimum, int maximum)
        : min(minimum), max(maximum)
        {}

    int getRange() const
    {
        return max-min;
    }

    vector<int> toVector()
    {
        return {min,max};
    }
};

class range_t_comp
{
public:
    bool operator() (range_t r1, range_t r2)
    {
        return r1.getRange() > r2.getRange();
    }
};

int findSmallestIterator(vector<vector<int>::iterator> its)
{
    // Size check
    int smallestIndex = 0;
    for (int i = 0; i < its.size(); ++i)
    {
        if (*its[i] < *its[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    return smallestIndex;
}

int findLargestIterator(vector<vector<int>::iterator> its)
{
    // Size check
    int largestIndex = 0;
    for (int i = 0; i < its.size(); ++i)
    {
        if (*its[i] > *its[largestIndex])
        {
            largestIndex = i;
        }
    }

    return largestIndex;
}

vector<int> smallestRange(vector<vector<int>>& nums) 
{
    vector<vector<int>::iterator> its;
    priority_queue<range_t, vector<range_t>, range_t_comp> q;

    // Intitialize our list of iterators to the first item in each list
    for (auto& vec : nums)
    {
        vector<int>::iterator i(vec.begin());
        its.push_back(i);
    }

    // Now create our range from the smallest and largest iterator at each index
    int smallestIndex = 0;
    int largestIndex = 0;
    while(its[smallestIndex] != nums[smallestIndex].end())
    {
        smallestIndex = findSmallestIterator(its);
        largestIndex = findLargestIterator(its);

        // We now have a valid range, throw it into our min heap
        q.push(range_t(*its[smallestIndex], *its[largestIndex]));

        // Increment the smallest iterator and loop again
        ++its[smallestIndex];
    }

    range_t range = q.top();
    return range.toVector();
}

int main()
{
    vector<vector<int>> vec = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> range = smallestRange(vec);

    cout << "{" << range[0] << "," << range[1] << "}";
}