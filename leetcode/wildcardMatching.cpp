#include <iostream>
#include <string>

using namespace std;

const char SINGLE_CHAR = '?';
const char ANY_CHAR = '*';  // NOTE: also matches empty sequence

bool isMatch(string s, string p)
{
    int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

    for(i=0,j=0 ; i<slen; ++i, ++j)
    {
        if(p[j]=='*')
        { //meet a new '*', update traceback i/j info
            iStar = i;
            jStar = j;
            --i;
        }
        else
        { 
            if(p[j]!=s[i] && p[j]!='?')
            {  // mismatch happens
                if(iStar >=0)
                { // met a '*' before, then do traceback
                    i = iStar++;
                    j = jStar;
                }
                else return false; // otherwise fail
            }
        }
    }
    
    while(p[j]=='*') ++j;
    return j==plen;
}

int main()
{
    cout << isMatch("aa", "aa") << endl;
    cout << isMatch("aa", "ab") << endl;
    cout << isMatch("aa", "a?") << endl;
    cout << isMatch("aa", "*") << endl;
    cout << isMatch("", "*") << endl;
    cout << isMatch("", "ab") << endl;
    cout << isMatch("", "*?") << endl;
}