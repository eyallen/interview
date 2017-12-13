#include <iostream>
#include <vector>

using namespace std;

void sortedMerge(vector<int>& a, vector<int> b)
{
    int insertPos = a.size() - 1;
    int indexA = a.size() - b.size() - 1;
    int indexB = b.size() - 1;
    while(indexA >= 0 || indexB >= 0)
    {
        if (indexA >= 0 && indexB >= 0)
        {
            if (a[indexA] > b[indexB])
            {
                a[insertPos] = a[indexA];
                --indexA;
            }
            else
            {
                a[insertPos] = b[indexB];
                --indexB;
            }
        }
        else if (indexA >= 0)
        {
            a[insertPos] = a[indexA];
            --indexA;
        }
        else
        {
            a[insertPos] = b[indexB];
            --indexB;
        }
        
        --insertPos;
    }

    return;
}

int main()
{
    vector<int> a = {5,8,10,0,0,0};
    vector<int> b = {1,4,15};

    sortedMerge(a, b);

    for(int i : a)
    {
        cout << i << " ";
    }
}