#include <iostream>
#include <string>
#include <climits>

using namespace std;

/*
 * Implement atoi to convert a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
 * Then, starting from this character, takes an optional initial plus or minus sign followed by as many 
 * numerical digits as possible, and interprets them as a numerical value.
 */
int myAtoi(string str) 
{
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

int main()
{
    cout << myAtoi("    010") << endl;
}