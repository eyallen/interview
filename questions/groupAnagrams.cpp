#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int* createHash(string str)
{
    int hash[256] = {0};

    for (const auto& c : str)
    {
        hash[c]++;
    }

    return hash;
}

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    // ERORR CHECKING
    unordered_map<int*, unordered_set<string>> map;

    for (const auto& s : strs)
    {
        int* hash = createHash(s);
        if(map.find(hash) != map.end())
        {
            map[hash].insert(s);
        }
        else 
        {
            map[hash] = unordered_set<string>({s});
        }
    }

    vector<vector<string>> result;

    for (const auto& it : map)
    {
        vector<string> strs;

        for (const auto& str : it.second)
        {
            strs.push_back(str);
        }

        result.push_back(strs);
    }

    return result;
}

int main()
{
    vector<vector<string>> result = groupAnagrams({"aab","bbc","baa","xxx"});
}