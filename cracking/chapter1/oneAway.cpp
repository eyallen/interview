#include <iostream>
#include <string>

using namespace std;

/*
 * Determine if two strings are one edit away: insert, delete, replace.
 */
bool oneAway(string str1, string str2)
{
    if (str1 == str2)
    {
        return true;
    }

    string string1 = str1.length() > str2.length() ? str1 : str2;
    string string2 = str1.length() > str2.length() ? str2 : str1;

    int index1 = 0;
    int index2 = 0;
    int foundDifference = false;
    while (index1 < string1.length() && index2 < string2.length())
    {
        if (string1.at(index1) != string2.at(index2))
        {
            if (foundDifference) 
            {
                return false;
            }
            foundDifference = true;
            if (string1.length() == string2.length())
            {
                index2++;
            }
        }
        else
        {
            index2++;
        }

        index1++;
    }

    return true;
}

int main()
{
    cout << oneAway("pale", "ple") << endl;
    cout << oneAway("pales", "pale") << endl;
    cout << oneAway("pale", "bale") << endl;
    cout << oneAway("pale", "bake") << endl;
}