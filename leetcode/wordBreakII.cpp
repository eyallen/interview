#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> combine(string word, vector<string> prev)
{
    for (int i = 0; i < prev.size(); ++i)
    {
        prev[i] = prev[i] + " " + word;
    }

    return prev;
}

vector<string> wordBreakDict(string s, unordered_set<string> dict, unordered_map<string, vector<string>>& memo)
{
    vector<string> result;

    if (memo.find(s) != memo.end())
    {
        return memo[s];
    }

    if (dict.find(s) != dict.end())
    {
        result.push_back(s);
    }

    for (int i = 1; i < s.size(); ++i)
    {
        string word = s.substr(i);
        if (dict.find(word) != dict.end())
        {
            string removed = s.substr(0, i);
            vector<string> prev = combine(word, wordBreakDict(removed, dict, memo));
            result.insert(result.end(), prev.begin(), prev.end());
        }
    }

    memo[s] = result;
    return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string> dict;
    for (const auto& word : wordDict)
    {
        dict.insert(word);
    }

    unordered_map<string, vector<string>> memoTable;
    return wordBreakDict(s, dict, memoTable);
}

int main()
{
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> breaks = wordBreak("catsanddog", dict);

    cout << "[";
    for (const auto& str : breaks)
    {
        cout << str << ","; 
    }
    cout << "]" << endl;
}