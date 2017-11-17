#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
bool isValid(string s) 
{
    stack<char> paren;

    for(string::iterator it = s.begin(); it != s.end(); ++it)
    {
        switch(*it)
        {
            case '(':
            case '[':
            case '{':
                paren.push(*it);
                break;
            case ')':
                if (paren.empty() || paren.top() != '(')
                {
                    return false;
                }
                paren.pop();
                break;
            case ']':
                if (paren.empty() || paren.top() != '[')
                {
                    return false;
                }
                paren.pop();
                break;
            case '}':
                if (paren.empty() || paren.top() != '{')
                {
                    return false;
                }
                paren.pop();
                break;
            default:
                break;
        }
    }

    return paren.empty();
}

int main()
{
    cout << isValid("(){}[]") << "\n";
}