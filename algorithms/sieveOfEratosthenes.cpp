#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int n)
{
    vector<int> results = vector<int>();
    vector<bool> grid = vector<bool>(n, false);
    int limit = sqrt(n);

    for (int i = 2; i < limit; ++i)
    {
        for (int x = i + i; x <= n; x += i)
        {
            grid[x] = true;
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        if (!grid[i])
        {
            results.push_back(i);
        }
    }

    return results;
}

int main()
{
    vector<int> r = sieve(100);

    for (int i : r)
    {
        cout << i << " ";
    }
}