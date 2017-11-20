#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& s)
{
    stack<int> temp = stack<int>();
    while(!s.empty())
    {
        int val = s.top();
        s.pop();

        while(!temp.empty() && temp.top() > val)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(val);
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> toSort = stack<int>();
    toSort.push(7);
    toSort.push(10);
    toSort.push(5);
    toSort.push(12);
    toSort.push(8);
    toSort.push(3);
    toSort.push(1);
    sortStack(toSort);
    
    while(!toSort.empty())
    {
        cout << toSort.top() << " ";
        toSort.pop();
    }
    cout << endl;
}