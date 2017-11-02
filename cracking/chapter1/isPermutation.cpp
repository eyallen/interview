#include <iostream>
#include <string>

using namespace std;

/*
 * Determin if str2 is a permutation of str1. Assume we care about capitalization
 * and that we are using the ASCII char set.
 * A string is a permutation if it:
 * 1. Is the same length
 * 2. Contains the same count of characters.
 * 3. Is in a different order (i.e. abc is not a permutation of abc)
 */
bool isPermutation(string str1, string str2)
{
    if (str1.empty() || str2.empty() || str1.length() != str2.length() || str1 == str2)
    {
        return false;
    }

    // map each character to a count of characters for str1
    int charCount[128] = {0};

    for (string::iterator it = str1.begin(); it != str1.end(); ++it)
    {
        charCount[*it]++;
    }

    // Now determine if we have the same number of characters in str2
    for (string::iterator it = str2.begin(); it != str2.end(); ++it)
    {
        charCount[*it]--;
        if (charCount[*it] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << isPermutation("abc", "bac") << endl;
    cout << isPermutation("abc", "bAc") << endl;
}