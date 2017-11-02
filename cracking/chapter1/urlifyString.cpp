#include <iostream>
#include <string>

using namespace std;

void urlifyString(string& str, size_t trueLength) 
{
    // If we have an empty string or the string contains no spaces, just return
    if (str.empty() || str.length() == trueLength)
    {
        return;
    }

    int left = trueLength - 1;
    int right = str.length() - 1;

    while (left >= 0 && right >= 0 && left != right)
    {
        if (str.at(left) != ' ')
        {
            char c = str.at(left);
            str[left] = str[right];
            str[right] = c;
            --left;
            --right;
        }
        else
        {
            str.replace(right-2, 3, "%20");
            right = right - 3;
            --left;
        }
    }
}

int main()
{
    string str = "a b  ";
    
    urlifyString(str, 3); 
    cout << str << endl;

    str = "a b c    ";
    
    urlifyString(str, 5); 
    cout << str << endl;

    str = "   ";
    
    urlifyString(str, 1); 
    cout << str << endl;

    str = "      ";
    
    urlifyString(str, 2); 
    cout << str << endl;

    str = "abc";
    
    urlifyString(str, 3); 
    cout << str << endl;

    str = " a  ";
    
    urlifyString(str, 2); 
    cout << str << endl;
}