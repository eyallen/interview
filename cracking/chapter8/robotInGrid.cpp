#include <iostream>
#include <vector>

using namespace std;

struct Tile
{
    int row = 0;
    int col = 0;
    bool isValid = true;

    Tile(int r, int c, bool valid)
        : row(r), col(c), isValid(valid)
    {}
};

/*
 * Imagine a robot sitting in the upper left corner of a grid that can move right or down.
 * Certains cells are off limits such that the robot cannot move there.
 * Design an algorithm to determine a path to the bottom right
 */
vector<Tile> getValidPath(Tile map[2][2], int r, int c)
{
    // Assume we don't get passed a value > map size
    if (r < 0 || c < 0 || !map[r][c].isValid)
    {
        return {};
    }

    if (r == 0 && c == 0)
    {
        vector<Tile> path = vector<Tile>();
        path.push_back(map[0][0]);
        return path;
    }

    vector<Tile> pathUp = getValidPath(map, r-1, c);
    vector<Tile> pathLeft = getValidPath(map, r, c-1);

    if (!pathUp.empty())
    {
        pathUp.push_back(map[r][c]);
        return pathUp;
    }
    if (!pathLeft.empty())
    {
        pathLeft.push_back(map[r][c]);
        return pathLeft;
    }

    return {};
}

int main()
{
    /*
     *   | | |
     *   | | |
     */
    Tile map[2][2] = 
    {
        { Tile(0,0,true), Tile(0,1,true)},
        { Tile(1,0,true), Tile(1,1,true)},
    };

    vector<Tile> path = getValidPath(map, 1, 1);

    /*
     *   | |X|
     *   | | |
     */
    Tile map2[2][2] = 
    {
        { Tile(0,0,true), Tile(0,1,false)},
        { Tile(1,0,true), Tile(1,1,true)},
    };

    vector<Tile> path2 = getValidPath(map2, 1, 1);

    /*
     *   | | |
     *   | |X|
     */
    Tile map3[2][2] = 
    {
        { Tile(0,0,true), Tile(0,1,true)},
        { Tile(1,0,true), Tile(1,1,false)},
    };

    vector<Tile> path3 = getValidPath(map3, 1, 1);
}
