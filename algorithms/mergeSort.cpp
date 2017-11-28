#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeVectors(vector<int> a, vector<int> b)
{
    vector<int> merged = vector<int>();

    int iA = 0;
    int iB = 0;

    while(iA < a.size() || iB < b.size())
    {
        if (iA < a.size() && iB < b.size())
        {
            if (a[iA] <= b[iB])
            {
                merged.push_back(a[iA]);
                iA++;
            }
            else
            {
                merged.push_back(b[iB]);
                iB++;
            }
        }
        else if (iA < a.size())
        {
            merged.push_back(a[iA]);
            iA++;
        }
        else if (iB < b.size())
        {
            merged.push_back(b[iB]);
            iB++;
        }
    }

    return merged;
}

vector<int> mergeSort(vector<int> vec)
{
    if (vec.size() <= 1)
    {
        return vec;
    }

    int middle = vec.size() / 2;
    vector<int> left = vector<int>(vec.begin(), vec.begin() + middle);
    vector<int> right = vector<int>(vec.begin() + middle, vec.end());

    return mergeVectors(mergeSort(left), mergeSort(right));
}

int main()
{
    vector<int> toSort = {10,1,3,6,7,8,2};
    vector<int> sorted = mergeSort(toSort);

    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
}