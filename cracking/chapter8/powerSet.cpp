#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> findSubsets(vector<char> set)
{
    if (set.empty())
    {
        vector<char> emptySet = {};
        return {emptySet};
    }

    char toMerge = set.back();
    set.pop_back();
    
    vector<vector<char>> subs = findSubsets(set);
    vector<vector<char>> newSubs = {};

    for (int i = 0; i < subs.size(); ++i)
    {
        vector<char> v = {toMerge};
        v.insert(v.end(), subs[i].begin(), subs[i].end());
        newSubs.push_back(v);
    }

    subs.push_back({toMerge});
    subs.insert(subs.end(), newSubs.begin(), newSubs.end());

    return subs;
}

void printVector(vector<char> v)
{
    cout << '{';
    for (char c : v)
    {
        cout << "\'" << c << "\'";
    }

    cout << '}';
}

void printAllSubs(vector<vector<char>> subs)
{
    cout << '{';
    for (vector<char> v : subs)
    {
        printVector(v);
        cout << " ";
    }

    cout << '}' << endl;
}

int main()
{
    vector<char> set = {'a','b', 'c','d'};
    vector<vector<char>> subSets = findSubsets(set);
    printAllSubs(subSets);
}