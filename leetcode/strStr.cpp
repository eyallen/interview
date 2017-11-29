#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) 
{
    if (needle.length() > haystack.length())
    {
        return -1;
    }

    if (!needle.length())
    {
        return 0;
    }

    for (int i = 0; i < haystack.length(); ++i)
    {
        bool found = true;
        for (int j = 0; j < needle.length(); ++j)
        {
            if (haystack[i+j] != needle[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string haystack = "hello";
    string needle = "ll";

    cout << strStr(haystack, needle) << endl;

    haystack = "aaaaa";
    needle = "bb";

    cout << strStr(haystack, needle) << endl;

    haystack = "aaaaabba";
    needle = "bb";

    cout << strStr(haystack, needle) << endl;

    haystack = "";
    needle = "";

    cout << strStr(haystack, needle) << endl;
}