#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if (strs.size() == 0)
    {
        return "";
    }

    string prefix;
    for(int i = 0; i < strs[0].size(); ++i)
    {
        for (int j = 1; j < strs.size(); ++j)
        {
            if (strs[j].length() <= i || strs[0][i] != strs[j][i])
            {
                return prefix;
            }
        }

        prefix += strs[0][i];
    }

    return prefix;
}

int main()
{
    vector<string> vec = {"abc", "ab", "a"};
    cout << longestCommonPrefix(vec) << "\n";

    vec = {"abc", "abcd", "ab"};
    cout << longestCommonPrefix(vec) << "\n";

    vec = {"a", "a", "b"};
    cout << longestCommonPrefix(vec) << "\n";

    vec = {"abca", "abc"};
    cout << longestCommonPrefix(vec) << "\n";

    vec = {"abc"};
    cout << longestCommonPrefix(vec) << "\n";

    vec = {};
    cout << longestCommonPrefix(vec) << "\n";
}