#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * Given a roman numeral, convert it to an integer.
 */
int romanToInt(string s)
{
    int result = 0;
    int prevVal = 0;

    unordered_map<char, int> numeralToInt =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for (string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
    {
        int val = numeralToInt[*rit];
        val < prevVal ? result-= val : result += val;
        prevVal = val;
    }

    return result;
}

int main()
{
    cout << romanToInt("III") << "\n";
    cout << romanToInt("IV") << "\n";
    cout << romanToInt("VI") << "\n";
    cout << romanToInt("XI") << "\n";
    cout << romanToInt("IX") << "\n";
    cout << romanToInt("XX") << "\n";
    cout << romanToInt("XL") << "\n";
    cout << romanToInt("XXIV") << "\n";
    cout << romanToInt("XC") << "\n";
    cout << romanToInt("XCII") << "\n";
    cout << romanToInt("LXIV") << "\n";
}