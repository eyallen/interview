#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> findStartPosition(vector<vector<char>>& board, char c)
{
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[row].size(); col++)
        {
            if (board[row][col] == c)
            {
                return {row,col};
            }
        }
    }

    return {-1,-1};
}

bool pathExists(vector<vector<char>>& board, int r, int c, string word, int pos)
{
    if (r < 0 || c < 0 || pos > word.length())
    {
        return false;
    }

    if (word[pos] == 0)
    {
        return true;
    }

    if (r >= board.size() || c >= board[0].size())
    {
        return false;
    }

    if (board[r][c] == word[pos])
    {
        // Mark this as 'visited' by setting it to null
        board[r][c] = 0;

        // Otherwise, increment char and try all adjacent
        bool found = pathExists(board, r+1,c, word, pos+1) ||
                    pathExists(board, r-1,c, word, pos+1) ||
                    pathExists(board, r,c+1, word, pos+1) ||
                    pathExists(board, r,c-1, word, pos+1);
        
        if (!found)
        {
            // Reset the character
            board[r][c] = word[pos];
        }

        return found;
    }

    return false;
}

/*
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally 
 * or vertically neighboring. The same letter cell may not be used more than once.
 */
bool exist(vector<vector<char> >& board, string word) 
{
    if (word.empty())
    {
        return false;
    }

    if (word == "")
    {
        return true;
    }

    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[0].size(); c++)
        {
            if (pathExists(board, r, c, word, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<char> r1 = {'A','B','C'};
    vector<char> r2 = {'D','B','F'};
    vector<char> r3 = {'G','D','I'};

    vector<vector<char>> board = vector<vector<char>>();
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);

    cout << exist(board, "BDIFCBB") << endl;

    r1 = {'A','B'};
    r2 = {'C','D'};

    board = vector<vector<char>>();
    board.push_back(r1);
    board.push_back(r2);

    cout << exist(board, "ABDC") << endl;
}