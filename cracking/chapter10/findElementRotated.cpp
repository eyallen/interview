#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int> v, int x, int first, int last)
{
    if (first > last)
    {
        return -1;
    }

    int mid = (first + last) / 2;

    if (v[mid] == x)
    {
        return mid;
    }

    if (v[first] < v[mid]) // Left side is ordered correctly
    {
        if (x < v[mid] && x >= v[first])
        {
            return findElement(v, x, 0, mid-1);
        }
        else
        {
            return findElement(v, x, mid+1, last);
        }
    }
    else if (v[mid] < v[last]) // Right side sorted normally
    {
        if (x > v[mid] && x <= v[last])
        {
            return findElement(v, x, mid+1, last);
        }
        else
        {
            return findElement(v, x, first, mid-1);
        }
    }
    else if (v[mid] == v[first])
    {
        if (v[mid] != v[last])
        {
            return findElement(v, x, mid+1, last);
        }
        else
        {
            int result = findElement(v, x, first, mid-1);
            if (result == -1)
            {
                return findElement(v, x, mid+1, last);
            }
            else
            {
                return result;
            }
        }
    }

    return -1;
}


int main()
{
    vector<int> v = {15,16,19,20,25,1,3,4,5,7,10,14};
    cout << findElement(v, 1, 0, v.size()-1) << endl;

    v = {20,20,20,20,20,1,3,4,5,7,10,14};
    cout << findElement(v, 20, 0, v.size()-1) << endl;
}