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

int findMagicNonDistinct(vector<int> vec, int index, int offset)
{
    if (index < 0 || index >= vec.size())
    {
        return -1;
    }

    if (vec[index] == index+offset)
    {
        return index+offset;
    }

    // Search left
    int leftIndex = min(vec[index], index+offset);

    // Search right
    

    return -1;
}

int findMagicIndexNonDistinct(vector<int> vec)
{
    return findMagicNonDistinct(vec, vec.size() / 2, 0);
}

int main()
{
    cout << findMagicIndexDistinct({0,1,2,3,4}) << endl;
    cout << findMagicIndexDistinct({-1,0,1,3,4}) << endl;
    cout << findMagicIndexDistinct({0,5,6,7,8}) << endl;
    cout << findMagicIndexDistinct({-10,-5,1,2,4}) << endl;
}