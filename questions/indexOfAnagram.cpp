#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// { a: 1, b: 2, c: 1}
// { a: 1, b: 2, c: 2}
// { c: 2, x: 1, a: 1}
// { b: 2, c: 1, a: 1}
bool areEqualHashes(unordered_map<char,int> one, unordered_map<char,int> two)
{
    if (one.size() != two.size())
    {
        return false;
    }

    for (const auto& n : one)
    {
        auto twoIt = two.find(n.first);
        if (twoIt == two.end() || twoIt->second != n.second)
        {
            return false;
        }
    }

    return true;
}

unordered_map<char,int> createHash(string str)
{
    unordered_map<char,int> hash;

    for (const auto& c : str)
    {
        if (hash.find(c) != hash.end())
        {
            hash[c]++;
        }
        else
        {
            hash[c] = 1;
        }
    }

    return hash;
}

int indexOfAnagram(string str, string sub)
{
    if (sub.empty() || sub.size() > str.size())
    {
        return -1;
    }

    unordered_map<char,int> subHash = createHash(sub);

    for (int i = 0; i <= str.size() - sub.size(); i++)
    {
        string s = str.substr(i, sub.size());
        unordered_map<char,int> sHash = createHash(s);

        if (areEqualHashes(sHash, subHash))
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    cout << indexOfAnagram("hellothere", "leh") << endl;
    cout << indexOfAnagram("hellothere", "oth") << endl;
    cout << indexOfAnagram("hellothere", "") << endl;
    cout << indexOfAnagram("hellothere", "e") << endl;
    cout << indexOfAnagram("hellothere", "er") << endl;
}