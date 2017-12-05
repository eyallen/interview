#include <iostream>
#include <bitset>

using namespace std;

/*
 * Given two 32 bit numbers, n and m, and two bit positions i and j write a method
 * to insert m into n such that m starts at bit j and ends at i.
 */
int insertBit(int n, int m, int i, int j)
{
    // First we need to clear the bits in n at position j through i
    int allOnes = ~0;

    // 1s before j, then 0s
    int left = allOnes << (j + 1);

    // 1s after i
    int right = ((1 << i) - 1);

    int mask = left | right;
    
    // Now clear bits j through i
    n = n & mask;

    // Now shift m over by i bits and add to n
    m = m << i;
    return n | m;
}

int main()
{
    int result = insertBit(1024, 19, 2, 6);
    cout << bitset<32>(result) << endl;
}