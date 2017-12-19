#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void findDuplicates(vector<int> list)
{
    bitset<32000> mask;

    for (const auto& num : list)
    {
        int n = num -1;
        if (mask.test(n))
        {
            cout << num << " ";
        }
        else
        {
            mask.set(n);
        }
    }
}

int main()
{
    vector<int> l = {1,1,32000,32000,3,4,5,6,7,1,7};
    findDuplicates(l);
}