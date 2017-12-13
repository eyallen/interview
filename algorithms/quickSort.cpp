#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> v)
{
    if (v.size() < 2)
    {
        return v;
    }

    vector<int> left;
    vector<int> right;
    int pivotValue = v[v.size() - 1];

    // Ensure pivot is removed
    v.pop_back();

    for (int i = 0; i < v.size(); ++i)
    {
        v[i] < pivotValue ? left.push_back(v[i]) : right.push_back(v[i]);
    }

    vector<int> sl = quickSort(left);
    vector<int> sr = quickSort(right);
    sl.insert(sl.end(), pivotValue);
    sl.insert(sl.end(), sr.begin(), sr.end());

    return sl;
}

int main()
{
    vector<int> list = {4,5,1,2,7,3,6};
    vector<int> sorted = quickSort(list);

    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
}