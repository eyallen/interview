#include <iostream>
#include <stack>

using namespace std;

template<class T>
class SortedStack
{
public:
    SortedStack()
    {
        _stack = stack<T>();
    }

    void Insert(T val)
    {
        if (_stack.empty() || _stack.top() >= val)
        {
            _stack.push(val);
            return;
        }

        stack<T> tempStack = stack<T>();
        bool itemInserted = false;

        // Empty the stack into a temp stack, inserting the item in sorted order
        while (!_stack.empty())
        {
            if (val <= _stack.top() && !itemInserted)
            {
                tempStack.push(val);
                itemInserted = true;
            }
            tempStack.push(_stack.top());
            _stack.pop();
        }

        // Now copy the sorted contents back to _stack so that the smallest elements are at the top
        while (!tempStack.empty())
        {
            _stack.push(tempStack.top());
            tempStack.pop();
        }

        return;
    }

    T Peek()
    {
        return _stack.top();
    }

private:
    stack<T> _stack;
};

int main()
{
    SortedStack<int> sort = SortedStack<int>();

    sort.Insert(10);
    sort.Insert(5);
    sort.Insert(2);
    cout << sort.Peek() << endl;

    sort.Insert(11);
    cout << sort.Peek() << endl;

    sort.Insert(3);
    cout << sort.Peek() << endl;

    sort.Insert(0);
    cout << sort.Peek() << endl;
}