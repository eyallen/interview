#include <iostream>

using namespace std;

// Write a function to swap a number in place (no temp variables)
void swapNumbers(int& a, int& b)
{
    a += b;
    b = a - b;
    a -= b;
}

int main()
{
    int a = 5;
    int b = 10;
    swapNumbers(a, b);

    cout << "a: " << a << " b: " << b << endl;

    a = -10;
    b = 20;
    swapNumbers(a, b);

    cout << "a: " << a << " b: " << b << endl;

    a = 1;
    b = -1;
    swapNumbers(a, b);

    cout << "a: " << a << " b: " << b << endl;
}