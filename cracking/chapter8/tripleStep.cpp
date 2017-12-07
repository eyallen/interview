#include <iostream>
#include <vector>

using namespace std;

/*
 * A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3.
 * Implement a method to return the count of how many possible ways a child can run up the stairs.
 */
int tripleStep(int n, vector<int>& memo)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    if (memo[n] == -1)
    {
        // NOTE: I'm ignoring overflow here...
        memo[n] = tripleStep(n-1, memo) + tripleStep(n-2, memo) + tripleStep(n-3, memo);;
    }

    return memo[n];
}

int tripleStep(int n)
{
    vector<int> memo = vector<int>(n+1, -1);
    return tripleStep(n, memo);
}

int main()
{
    cout << tripleStep(1) << endl;
    cout << tripleStep(2) << endl;
    cout << tripleStep(3) << endl;
    cout << tripleStep(4) << endl;
    cout << tripleStep(5) << endl;
    cout << tripleStep(6) << endl;
}