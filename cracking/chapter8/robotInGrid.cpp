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
bool getValidPath(Tile map[2][2], int r, int c, vector<Tile>& path)
{
    // Assume we don't get passed a value > map size
    // TODO: We should store off tiles we already visition for O(rc);
    if (r < 0 || c < 0 || !map[r][c].isValid)
    {
        return false;
    }

    if (r == 0 && c == 0)
    {
        path.push_back(map[0][0]);
        return true;
    }

    if (getValidPath(map, r-1, c, path) || getValidPath(map, r, c-1, path))
    {
        path.push_back(map[r][c]);
        return true;
    }
    
    return false;
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

    vector<Tile> path = vector<Tile>();
    cout <<  getValidPath(map, 1, 1, path);

    /*
     *   | |X|
     *   | | |
     */
    Tile map2[2][2] = 
    {
        { Tile(0,0,true), Tile(0,1,false)},
        { Tile(1,0,true), Tile(1,1,true)},
    };

    vector<Tile> path2 = vector<Tile>();
    cout << getValidPath(map2, 1, 1, path2);

    /*
     *   | | |
     *   | |X|
     */
    Tile map3[2][2] = 
    {
        { Tile(0,0,true), Tile(0,1,true)},
        { Tile(1,0,true), Tile(1,1,false)},
    };

    vector<Tile> path3 = vector<Tile>();
    cout << getValidPath(map3, 1, 1, path3);
}
