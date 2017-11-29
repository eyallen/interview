#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
    int found = 0;
    int lastIndex = nums.size() - 1;
    for(int ri = lastIndex; ri >= 0; --ri)
    {
        if (nums[ri] == val)
        {
            nums[ri] = nums[lastIndex-found];
            found++;
        }
    }

    return nums.size() - found;
}

int main()
{
    vector<int> vec = {3,3,2};
    cout << removeElement(vec, 3) << endl;

    vec = {1,2,3};

    cout << removeElement(vec, 3) << endl;

    vec = {1,2,3};

    cout << removeElement(vec, 4) << endl;

    vec = {3};

    cout << removeElement(vec, 3) << endl;
    cout << removeElement(vec, 3) << endl;
}