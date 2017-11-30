#include<io stream>
#include <vector>

using namespace std;

// TODO: We can do this with log(n) with a modified binary search
int searchInsert(vector<int>& nums, int target) 
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int insertIndex = 0;
    for(int n : nums)
    {
        if (target <= n)
        {
            return insertIndex;
        }

        insertIndex++;
    }

    return insertIndex++;
}

int main()
{
}
