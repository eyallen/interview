#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int computeSum(vector<int> v)
{
    int sum = 0;

    for (const auto& i : v)
    {
        sum += i;
    }

    return sum;
}

unordered_map<int,int> buildLocationMap(vector<int> v)
{
    unordered_map<int, int> map;

    for (int i = 0; i < v.size(); ++i)
    {
        if (map.find(v[i]) == map.end())
        {
            map[v[i]] = i;
        }
    }

    return map;
}

void sumSwap(vector<int> a, vector<int> b)
{
    int sumA = computeSum(a);
    int sumB = computeSum(b);

    int sumDiff = sumA - sumB;
    if (sumDiff % 2 != 0)
    {
        // error case
        cout << "error" << endl;
        return;
    }

    unordered_map<int, int> locMapA = buildLocationMap(a);

    for (const auto& i : b)
    {
        int toFind = sumDiff/2 + i;
        if (locMapA.find(toFind) != locMapA.end())
        {
            cout << "{" << i << "," << toFind << "}" << endl;
            return;
        }
    }

    return;
}

int main()
{
    sumSwap({4,1,2,1,1,2},{3,6,3,3});
    sumSwap({4,1},{2});
    sumSwap({1,1,1},{1,1,1});
}