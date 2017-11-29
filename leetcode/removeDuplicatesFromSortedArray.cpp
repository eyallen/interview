#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
 */
int removeDuplicates(vector<int>& nums)
{
    int count = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i-1])
        {
            count++;
        }
        else 
        {
            nums[i-count] = nums[i];
        }
    }

    return nums.size()-count;
}

int main()
{
    vector<int> toUnDupe = {1,1,2,2,3};

    int size = removeDuplicates(toUnDupe);

    cout << size;
}