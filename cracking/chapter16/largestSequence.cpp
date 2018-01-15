#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int largestSequence(vector<int> sequence)
{
    int largest = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < sequence.size(); ++i)
    {
        currentSum += sequence[i];
        if (currentSum > largest)
        {
            largest = currentSum;
        }
        if (currentSum <= 0)
        {
            // Start over
            currentSum = 0;
        }
    }

    return largest;
}

int main()
{
    vector<int> seq = { 2,-8,3,-2,4,-10};
    cout << largestSequence(seq) << endl;

    seq = { 2,-8,3,-2,4,-10,10};
    cout << largestSequence(seq) << endl;

    seq = {1,2,3,4,5,0,-5,0};
    cout << largestSequence(seq) << endl;
}