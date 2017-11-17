#include "../../datastructures/linkedList.h"
#include <climits>

using namespace std;
using namespace datastructures;

struct MinNode
{
    int value;
    int prevMin;

    MinNode(){}

    MinNode(int val, int prev)
    {
        value = val;
        prevMin = prev;
    }
};

class MinStack
{
public:

    int getMin()
    {
        return minValue;
    }

    void push(int value)
    {
        MinNode min(value, minValue);
        if (value < minValue)
        {
            minValue = value;
        }

        Node<MinNode>* node = new Node<MinNode>(min);
        node->next = head;
        head = node;
    }

    int pop()
    {
        if (head == nullptr)
        {
            // Do something smarter like throw
            return INT_MAX;
        }

        Node<MinNode>* ret = head;
        head = head->next;

        int popped = ret->value.value;
        minValue = ret->value.prevMin;

        delete ret;
        return popped;
    }

private:
    int minValue = INT_MAX;
    Node<MinNode>* head = nullptr;
};

int main()
{
    MinStack minStack;

    cout << minStack.getMin() << endl;

    minStack.push(10);
    cout << minStack.getMin() << endl;

    minStack.push(5);
    cout << minStack.getMin() << endl;

    minStack.push(25);
    cout << minStack.getMin() << endl;

    minStack.push(2);
    cout << minStack.getMin() << endl;

    minStack.pop();
    cout << minStack.getMin() << endl;
}