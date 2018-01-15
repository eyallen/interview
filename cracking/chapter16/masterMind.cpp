#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Result {
    int HitCount = 0;
    int SubHitCount = 0;

    Result(int h, int s) :
        HitCount(h), SubHitCount(s)
        {}  

    void Print()
    {
        cout << "hit: " << HitCount << " sub hit: " << SubHitCount << endl;
    }
};

struct NonHitCounts
{
    int RedCount = 0;
    int YellowCount = 0;
    int GreenCount = 0;
    int BlueCount = 0;

    void IncrementCount(char c)
    {
        if (c == 'R')
        {
            RedCount++;
        }
        else if (c == 'Y')
        {
            YellowCount++;
        }
        else if (c == 'G')
        {
            GreenCount++;
        }
        else if (c == 'B')
        {
            BlueCount++;
        }
    }
};

Result MasterMind(string guess, string sol)
{
    // TODO: error checking on string length - what to do if differing lengths?

    int hits = 0;
    int subHits = 0;
    NonHitCounts guessCounts;
    NonHitCounts solCounts;

    for (int i = 0; i < guess.length(); ++i)
    {
        if (guess[i] == sol[i])
        {
            hits++;
        }
        else
        {
            guessCounts.IncrementCount(guess[i]);
            solCounts.IncrementCount(sol[i]);
        }
    }

    subHits += min(guessCounts.RedCount, solCounts.RedCount);
    subHits += min(guessCounts.BlueCount, solCounts.BlueCount);
    subHits += min(guessCounts.YellowCount, solCounts.YellowCount);
    subHits += min(guessCounts.GreenCount, solCounts.GreenCount);

    return Result(hits, subHits);
}

int main()
{
    Result res = MasterMind("RRBB", "RRBB");
    res.Print();

    res = MasterMind("RBYY", "RRBB");
    res.Print();

    res = MasterMind("YYYY", "RBGG");
    res.Print();
}