#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TODO: doesn't actually take advantage of the sorted nature of the matrix
// Need to pop out sooner.
int findNthSmallest(vector<vector<int>> matrix, int n)
{
    priority_queue<int> q = priority_queue<int>();

    for (int r = 0; r < matrix.size(); ++r)
    {
        for (int c = 0; c < matrix[0].size(); ++c)
        {
            if (q.empty() || q.size() <= n)
            {
                q.push(matrix[r][c]);
            }
            else if (matrix[r][c] < q.top())
            {
                q.pop();
                q.push(matrix[r][c]);
            }
        }
    }

    return q.top();
}

int main()
{
    vector<vector<int>> m = 
    {
        {0, 1, 2},
        {3, 4, 7}
    };

    cout << findNthSmallest(m, 5) << endl;
}