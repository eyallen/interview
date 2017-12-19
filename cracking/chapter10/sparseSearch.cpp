#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sparseSearch(vector<string> vec, string str, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    // Find a mid that isn't an empty string
    int midOriginal = (low + high) / 2;
    int mid = midOriginal;

    while(vec[mid] == "" && mid >= low)
    {
        mid--;
    }

    if (vec[mid] == str)
    {
        return mid;
    }

    if (mid < low || vec[mid] < str)
    {
        // Search right
        return sparseSearch(vec, str, midOriginal+1, high);
    }
    else
    {
        // Search left
        return sparseSearch(vec, str, low, mid-1);
    }
}

int main()
{
    vector<string> v = {"","all","","","","ball","","bat"};
    cout << sparseSearch(v, "bat", 0, v.size()-1) << endl;
    cout << sparseSearch(v, "all", 0, v.size()-1) << endl;
    cout << sparseSearch(v, "ball", 0, v.size()-1) << endl;
}
