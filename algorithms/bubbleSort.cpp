#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& vec)
{
    bool additionalPass = false;

    for (int i = 0; i < vec.size() - 1; ++i)
    {
        if (vec[i] > vec[i+1])
        {
            int temp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = temp;

            additionalPass = true;
        }
    }

    if (additionalPass)
    {
        return bubbleSort(vec);
    }
}

int main()
{
    vector<int> toSort = {1,3,6,7,8,2};
    bubbleSort(toSort);

    for (int i = 0; i < toSort.size(); ++i)
    {
        cout << toSort[i] << " ";
    }
}