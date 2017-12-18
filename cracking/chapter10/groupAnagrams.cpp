#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string sortedChars(string str)
{
    string sorted = str;
    sort(sorted.begin(), sorted.end());
    return sorted;
}

vector<string> hashToVector(unordered_map<string, vector<string>> hash)
{
    vector<string> ret = vector<string>();

    for (const auto& n : hash)
    {
        for (const auto& str : n.second)
        {
            ret.push_back(str);
        }
    }

    return ret;
}

vector<string> groupAnagrams(vector<string> anagrams)
{
    unordered_map<string, vector<string>> hash = unordered_map<string, vector<string>>();
    for (const auto& str : anagrams)
    {
        string sorted = sortedChars(str);
        if (hash.find(sorted) != hash.end())
        {
            hash[sorted].push_back(str);
        }
        else
        {
            vector<string> v = vector<string>();
            v.push_back(str);
            hash[sorted] = v;
        }
    }

    return hashToVector(hash);
}

int main()
{
    vector<string> anagrams = {"aba", "tr", "aab", "baa", "rt", "wrt", "xyz"};
    vector<string> grouped = groupAnagrams(anagrams);

    for (const auto& str : grouped)
    {
        cout << str << " ";
    }
}