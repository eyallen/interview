#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/*
 * Reverse digits of an integer.
 */
int reverseInteger(int x)
{
    int reversed = 0;
    bool isNegative = x < 0;

    x = abs(x);

    for (int i = 0; x > 0; i++)
    {
        auto digit = x % 10;

        // Will we overflow?
        if (reversed > INT_MAX / 10)
        {
            return 0;
        }

        reversed = reversed * 10 + x % 10;

        // Did we overflow?
        if (reversed < 0)
        {
            return 0;
        }

        x /= 10;
    }

    return isNegative ? -reversed : reversed;
}

int main()
{
    cout << reverseInteger(123) << "\n";
    cout << reverseInteger(300) << "\n";
    cout << reverseInteger(-123) << "\n";
    cout << reverseInteger(1000000003) << "\n";
    cout << reverseInteger(1534236469) << "\n";
}