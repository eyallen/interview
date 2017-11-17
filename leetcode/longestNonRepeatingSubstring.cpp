#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// abcabcbb
// ji
int lengthOfLongestSubstring(string s) 
{
    if (s.length() == 0) return 0;

    unordered_map<char, int> charMap;
    int maxLength = 0;
    for (int i=0,j=0; i < s.length(); ++i)
    {
        auto c = s[i];
        if (charMap.count(c))
        {
            j = max(j, charMap[c] + 1);
        }

        charMap[c] = i;
        maxLength = max(maxLength, i-j+1);
    }

    return maxLength;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("bbbbb") << "\n";
    cout << lengthOfLongestSubstring("a") << "\n";
    cout << lengthOfLongestSubstring("") << "\n";
    cout << lengthOfLongestSubstring("pwwkew") << "\n";
}