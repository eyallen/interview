#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char,vector<char>> phoneMap = 
{
    {'2', {'a','b','c'}},
    {'3', {'d','e','f'}},
    {'4', {'g','h','i'}},
    {'5', {'j','k','l'}},
    {'6', {'m','n','o'}},
    {'7', {'p','q','r','s'}},
    {'8', {'t','u','v'}},
    {'9', {'w','x','y','z'}}
};

vector<string> mergeStrings(vector<string> strs, vector<char> chars)
{
    vector<string> merged = {};

    if (strs.empty())
    {
        for (const auto& c : chars)
        {
            merged.push_back(string(1,c));
        }

        return merged;
    }

    for (const auto& str : strs)
    {
        for (const auto& c : chars)
        {
            string s = str;
            s.append(1,c);
            merged.push_back(s);
        }
    }

    return merged;
}

vector<string> letterCombinations(string digits) 
{
    vector<string> combos = {};

    for (const auto& c : digits)
    {
        if (phoneMap.find(c) == phoneMap.end())
        {
            return {};
        }

        combos = mergeStrings(combos, phoneMap[c]);
    }

    return combos;
}

int main()
{
    vector<string> combo = letterCombinations("2");
    for (const auto& str : combo)
    {
        cout << str << ",";
    }
    cout << endl;

    combo = letterCombinations("23");
    for (const auto& str : combo)
    {
        cout << str << ",";
    }
    cout << endl;

    combo = letterCombinations("231");
    for (const auto& str : combo)
    {
        cout << str << ",";
    }
    cout << endl;
}