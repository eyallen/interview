#include <iostream>

using namespace std;

int main()
{
    int matrix[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << matrix[0][0] << "," << matrix[0][1] << "," << matrix[0][2] << endl;
    cout << matrix[1][0] << "," << matrix[1][1] << "," << matrix[1][2] << endl;
    cout << matrix[2][0] << "," << matrix[2][1] << "," << matrix[2][2] << endl;

    int n = 3;
    for (int layer = 0; layer < n/2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = matrix[first][i];

            // left -> top
            matrix[first][i] = matrix[last-offset][first];

            // bottom -> left
            matrix[last-offset][first] = matrix[last][last-offset];

            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }

    cout << endl;
    cout << matrix[0][0] << "," << matrix[0][1] << "," << matrix[0][2] << endl;
    cout << matrix[1][0] << "," << matrix[1][1] << "," << matrix[1][2] << endl;
    cout << matrix[2][0] << "," << matrix[2][1] << "," << matrix[2][2] << endl;
}