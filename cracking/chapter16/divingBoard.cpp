#include <iostream>
#include <unordered_set>

using namespace std;

// This is the recursive solution with memoization
void getAllLengths(int numBoards, int total, int shortLength, int longLength, unordered_set<int>& hash)
{
    if (numBoards <= 0)
    {
        hash.insert(total);
        return;
    }

    getAllLengths(numBoards - 1, total+shortLength, shortLength, longLength, hash);
    getAllLengths(numBoards - 1, total+longLength, shortLength, longLength, hash);
}

unordered_set<int> getAllPossibleLenghts(int numBoards, int shortLength, int longLength)
{
    unordered_set<int> lengths = unordered_set<int>();
    getAllLengths(numBoards, 0, shortLength, longLength, lengths);
    return lengths;
}


// This is the optimal solution