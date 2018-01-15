#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

vector<int> subSort(vector<int> vec)
{
    int leftStart = 0;
    int leftEnd = 0;
    int middleStart = 0;
    int middleEnd = 0;
    int rightStart = 0;
    int rightEnd = vec.size() - 1;

    // First find end of the left vector
    for (int i = 1; i < vec.size(); ++i)
    {
        // If we are no longer sorted, thats the end of the left vector
        if (vec[i] < vec[i-1])
        {
            leftEnd = (i-1);
            break;
        }
    }

    // Now find the start of the right vector
    for (int i = rightEnd -1; i >= 0; --i)
    {
        if(vec[i] > vec[i+1])
        {
            rightStart = (i+1);
            break;
        }
    }

    // The middle should now start and leftEnd+1 and end at rightStart -1
    middleStart = leftEnd+1;
    middleEnd = rightStart-1;

    // Since left and right are sorted, min == start and max == end
    // We need to store off the max/min for the middle section though
    int minMiddle = middleStart;
    int maxMiddle = middleStart;

    for (int i = middleStart; i <= middleEnd; ++i)
    {
        if (vec[i] < vec[minMiddle])
        {
            minMiddle = i;
        }
        if (vec[i] > vec[maxMiddle])
        {
            maxMiddle = i;
        }
    }

    // Now we need to expand our middle such that:
    // max(left) <= min(middle,right) AND
    // max(left,middle) <= min(right)

    for (; middleStart >= 0 && leftEnd >= 0; middleStart--, leftEnd--)
    {
        if (vec[leftEnd] <= min(vec[minMiddle], vec[rightStart]))
        {
            break;
        }

        if(vec[middleStart] < vec[minMiddle])
        {
            minMiddle = middleStart;
        }
        if (vec[middleStart] > vec[maxMiddle])
        {
            maxMiddle = middleStart;
        }
    }

    for (;middleEnd < vec.size() && rightStart < vec.size(); middleEnd++, rightStart++)
    {
        if (max(vec[leftEnd], vec[maxMiddle]) <= vec[rightStart])
        {
            break;
        }

        if(vec[middleEnd] < vec[minMiddle])
        {
            minMiddle = middleStart;
        }
        if (vec[middleEnd] > vec[maxMiddle])
        {
            maxMiddle = middleStart;
        }
    }

    return {middleStart, middleEnd};
}

int main()
{
    vector<int> sub = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    vector<int> res = subSort(sub);

    cout << res[0] << "," << res[1] << endl;
}