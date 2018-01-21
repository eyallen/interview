#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int currentVolume(int level, int fillLevel)
{
    return fillLevel - level;
}

int findLargestIndex(vector<int> histogram)
{
    int largestIndex = 0;

    for (int i = 1; i < histogram.size(); ++i)
    {
        if (histogram[i] > histogram[largestIndex])
        {
            largestIndex = i;
        }
    }

    return largestIndex;
}

int volumeLeftToRight(vector<int> histogram, int largestIndex)
{
    int volume = 0;
    int currentFillLevel = 0;

    for (int i = 0; i < largestIndex; ++i)
    {
        if (currentFillLevel > 0 && histogram[i] < currentFillLevel)
        {
            volume += currentVolume(histogram[i], currentFillLevel);
        }
        else if (currentFillLevel < histogram[i])
        {
            currentFillLevel = histogram[i];
        }
    }

    return volume;
}

int volumeRightToLeft(vector<int> histogram, int largestIndex)
{
    int volume = 0;
    int currentFillLevel = 0;

    for (int i = histogram.size()-1; i > largestIndex; --i)
    {
        if (currentFillLevel > 0 && histogram[i] < currentFillLevel)
        {
            volume += currentVolume(histogram[i], currentFillLevel);
        }
        else if (currentFillLevel < histogram[i])
        {
            currentFillLevel = histogram[i];
        }
    }

    return volume;
}

int computeHistogramVolume(vector<int> histogram)
{
    int largestIndex = findLargestIndex(histogram);
    int leftVolume = volumeLeftToRight(histogram, largestIndex);
    int rightVolume = volumeRightToLeft(histogram, largestIndex);

    return leftVolume+rightVolume;
}

int main()
{
    cout << computeHistogramVolume({0,0,4,0,0,6,0,0,3,0,5,0,1,0,0,0}) << endl;
    cout << computeHistogramVolume({0,0,4,0,0,2,0,0,0,1,0,2}) << endl;
}
