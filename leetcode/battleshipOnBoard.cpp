#include <iostream>
#include <vector>

using namespace std;

/*
X..X
...X
...X
*/

int countBattleships(vector<vector<char>>& board) 
{
    int count = 0;

    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[r].size(); c++)
        {
            if (board[r][c] == '.')
            {
                continue;
            }

            // We hit an X
            int prevCol = c - 1;
            int prevRow = r - 1;

            // We are on a horizontal ship
            if (prevCol >= 0 && board[r][prevCol] != '.')
            {
                continue;
            }

            // We are on a vertical ship
            if (prevRow >= 0 && board[prevRow][c] != '.')
            {
                continue;
            }

            // Otherwise we are at an edge or the prev row/col is a .
            // Therefore we have a new ship
            count++;
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> board =
    {
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };

    cout << countBattleships(board) << endl;

    board =
    {
        {'X','.','.','X'},
        {'X','.','.','X'},
        {'.','X','.','X'}
    };

    cout << countBattleships(board) << endl;

    board =
    {
        {'X','X','.','X'},
        {'.','.','.','X'},
        {'X','X','.','X'}
    };

    cout << countBattleships(board) << endl;

    board =
    {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','.','.','.'}
    };

    cout << countBattleships(board) << endl;
    
}