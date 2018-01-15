#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// This is the recursive solution with memoization
void getAllLengths(int numBoards, int total, int shortLength, int longLength, unordered_set<int>& hash, unordered_set<string>& visited)
{
    // If we have seen this combo before, return
    string key = to_string(numBoards) + " " + to_string(total);
    if (visited.find(key) != visited.end())
    {
        return;
    }

    if (numBoards <= 0)
    {
        hash.insert(total);
        return;
    }

    getAllLengths(numBoards - 1, total+shortLength, shortLength, longLength, hash, visited);
    getAllLengths(numBoards - 1, total+longLength, shortLength, longLength, hash, visited);

    visited.insert(key);
}

unordered_set<int> getAllPossibleLenghts(int numBoards, int shortLength, int longLength)
{
    unordered_set<int> lengths = unordered_set<int>();
    unordered_set<string> visited = unordered_set<string>();
    getAllLengths(numBoards, 0, shortLength, longLength, lengths, visited);
    return lengths;
}

// This is the optimal solution
unordered_set<int> getAllPossibleLengthsIterative(int numBoards, int shortLength, int longLength)
{
    unordered_set<int> lengths = unordered_set<int>();
    for (int numShort = 0; numShort <= numBoards; numShort++)
    {
        int total = (longLength * (numBoards-numShort)) + (shortLength * numShort);
        lengths.insert(total);
    }

    return lengths;
}