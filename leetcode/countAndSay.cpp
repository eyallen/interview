#include <iostream>
#include <string>

using namespace std;

// "11" -> "21"
string countOutString(string s, int n)
{
    if (n == 0)
    {
        return s;
    }

    string ret;
    for (string::iterator it = s.begin(); it != s.end();)
    {
        char currChar = *it;
        int currCharCount = 0;
        while(currChar == *it && it != s.end())
        {
            ++it;
            ++currCharCount;
        }

        ret += to_string(currCharCount);
        ret += currChar;
    }

    return countOutString(ret, n-1);
}

/*
 * 1. 1
 * 2. 11
 * 3. 21
 * 4. 1211
 * 5. 111221
 * 6. 312211
 * 7. 13112221
 */
string countAndSay(int n)
{
    return countOutString("1", n-1);
}

int main()
{
    cout << countAndSay(1) << "\n";
    cout << countAndSay(2) << "\n";
    cout << countAndSay(3) << "\n";
    cout << countAndSay(4) << "\n";
    cout << countAndSay(5) << "\n";
    cout << countAndSay(6) << "\n";
    cout << countAndSay(7) << "\n";
    cout << countAndSay(8) << "\n";
    cout << countAndSay(9) << "\n";
    cout << countAndSay(10) << "\n";
    cout << countAndSay(11) << "\n";
}