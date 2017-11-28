#include <iostream>

using namespace std;

/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    int digit = 0;
    int reversed = 0;
    int temp = x;
    while (temp > 0)
    {
        reversed *= 10;
        reversed += temp % 10;
        temp /= 10;
    }

    return reversed == x;
}

int main()
{
    cout << isPalindrome(1002) << endl;
}