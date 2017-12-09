#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMagicDistinct(vector<int> vec, int index, int offset)
{
    if (index < 0 || index >= vec.size())
    {
        return -1;
    }

    if (vec[index] == index+offset)
    {
        return index+offset;
    }

    if (vec[index] < index + offset)
    {
        // Search right
        vector<int> newVec = vector<int>(&vec[index]+1, &vec[vec.size()]);
        return findMagicDistinct(newVec, newVec.size()/2, index+1);
    }

    if (vec[index] > index + offset)
    {
        // Search left
        vector<int> newVec = vector<int>(&vec[0], &vec[index]);
        return findMagicDistinct(newVec, newVec.size()/2, offset);
    }

    return -1;
}

int findMagicIndexDistinct(vector<int> vec)
{
    return findMagicDistinct(vec, vec.size() / 2, 0);
}

int findMagicNonDistinct(int vec[], int size, int start, int end)
{
    if (end < start)
    {
        return -1;
    }
    
    int midIndex = (start+end) / 2;
    int midValue = vec[midIndex];
    if (midValue == midIndex)
    {
        return midIndex;
    }

    // Search left
    int leftIndex = min(midIndex-1, midValue);
    int left = findMagicNonDistinct(vec, size, start, leftIndex);
    if (left >= 0)
    {
        return left;
    }

    // Search right
    int rightIndex = max(midIndex+1, midValue);
    int right = findMagicNonDistinct(vec, size, rightIndex, end);

    return right;
}

int findMagicIndexNonDistinct(int vec[], int size)
{
    return findMagicNonDistinct(vec, size, 0, size -1);
}

int main()
{
    cout << findMagicIndexDistinct({0,1,2,3,4}) << endl;
    cout << findMagicIndexDistinct({-1,0,1,3,4}) << endl;
    cout << findMagicIndexDistinct({0,5,6,7,8}) << endl;
    cout << findMagicIndexDistinct({-10,-5,1,2,4}) << endl;

    cout << endl;

    int vec[4] = {0,0,0,0};
    cout << findMagicIndexNonDistinct(vec, 4) << endl;

    int vec2[4] = {1,1,3,4};
    cout << findMagicIndexNonDistinct(vec2, 4) << endl;

    int vec3[5] = {-10,-5,-1,-1,4};
    cout << findMagicIndexNonDistinct(vec3, 5) << endl;
}