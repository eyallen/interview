#include <iostream>
#include <vector>

using namespace std;

void computePondSize(int r, int c, vector<vector<int>>& plot, int &currentSize)
{
    if (r >= plot.size() || c >= plot.size() || plot[r][c] != 0)
    {
        return;
    }

    // Otherwise we have a pond
    currentSize++;

    // Invalidate the current plot so that we don't keep searching over the same pond
    plot[r][c] = -1;

    computePondSize(r+1,c,plot,currentSize);
    computePondSize(r-1,c,plot,currentSize);
    computePondSize(r,c+1,plot,currentSize);
    computePondSize(r,c-1,plot,currentSize);
    computePondSize(r+1,c-1,plot,currentSize);
    computePondSize(r-1,c-1,plot,currentSize);
    computePondSize(r+1,c+1,plot,currentSize);
    computePondSize(r-1,c+1,plot,currentSize);
}

vector<int> pondSizes(vector<vector<int>> plot)
{
    vector<int> sizes;

    for (int r = 0; r < plot.size(); ++r)
    {
        for (int c = 0; c < plot[r].size(); ++c)
        {
            int currentPondSize = 0;
            computePondSize(r,c,plot,currentPondSize);
            if (currentPondSize > 0)
            {
                sizes.push_back(currentPondSize);
            }
        }
    }

    return sizes;
}

int main()
{
    vector<vector<int>> plot =
    {
        {0,2,1,0},
        {0,1,0,1},
        {1,1,0,1},
        {0,1,0,1}
    };

    vector<int> sizes = pondSizes(plot);

    for (const auto& size : sizes)
    {
        cout << size << " ";
    }
    cout << endl;

    plot =
    {
        {0,2,1,0},
        {0,1,0,1},
        {0,1,0,1},
        {0,1,0,1}
    };

    sizes = pondSizes(plot);

    for (const auto& size : sizes)
    {
        cout << size << " ";
    }
    cout << endl;

    plot =
    {
        {0,2,1,0},
        {0,1,0,1},
        {0,0,0,1},
        {0,1,0,1}
    };

    sizes = pondSizes(plot);

    for (const auto& size : sizes)
    {
        cout << size << " ";
    }
    cout << endl;
}