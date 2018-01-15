#include <iostream>
#include <vector>

using namespace std;

enum SpaceType
{
    Blank,
    X,
    O
};

enum Direction
{
    Horizontal,
    Vertical,
    RightDiagonal,
    LeftDiagonal
};

int countContigousSpaces(SpaceType type, int startRow, int startCol, Direction dir, vector<vector<SpaceType>> board)
{
    // TODO: error checking of size
    // TODO: is blank a valid space type?

    int r = startRow;
    int c = startCol;
    int count = 0;

    for(; r < board.size() && c < board[r].size();)
    {
        if (board[r][c] != type)
        {
            return count;
        }

        count++;

        if (dir == Direction::Horizontal)
        {
            c++;
        } else if (dir == Direction::Vertical)
        {
            r++;
        } else if (dir == Direction::RightDiagonal)
        {
            r++;
            c++;
        } else { // LeftDiagonal
            r++;
            c--;
        }
    }

    return count;
}

bool isWin(SpaceType player, vector<vector<SpaceType>> board, int targetCount)
{
    return countContigousSpaces(player, 0, 0, Direction::Horizontal, board) == targetCount ||
           countContigousSpaces(player, 1, 0, Direction::Horizontal, board) == targetCount ||
           countContigousSpaces(player, 2, 0, Direction::Horizontal, board) == targetCount ||
           countContigousSpaces(player, 0, 0, Direction::RightDiagonal, board) == targetCount ||
           countContigousSpaces(player, 0, 0, Direction::Vertical, board) == targetCount ||
           countContigousSpaces(player, 0, 1, Direction::Vertical, board) == targetCount ||
           countContigousSpaces(player, 0, 2, Direction::Vertical, board) == targetCount ||
           countContigousSpaces(player, 0, 2, Direction::LeftDiagonal, board) == targetCount;
}

int main()
{
    vector<vector<SpaceType>> board = 
    {
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::X, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::X, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::X, SpaceType::Blank, SpaceType::Blank },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::X, SpaceType::X, SpaceType::X },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::X, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::Blank, SpaceType::X, SpaceType::Blank },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::X },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::Blank, SpaceType::Blank, SpaceType::X },
        { SpaceType::Blank, SpaceType::X, SpaceType::Blank },
        { SpaceType::X, SpaceType::Blank, SpaceType::Blank },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
        { SpaceType::X, SpaceType::X, SpaceType::X },
        { SpaceType::Blank, SpaceType::Blank, SpaceType::Blank },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;

    board = 
    {
        { SpaceType::X, SpaceType::Blank, SpaceType::X },
        { SpaceType::Blank, SpaceType::O, SpaceType::Blank },
        { SpaceType::X, SpaceType::Blank, SpaceType::X },
    };

    cout << isWin(SpaceType::X, board, 3) << endl;
}