#include "linkedListHelpers.h"
#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(Node* head, int size)
{
    if (head == nullptr || size == 0)
    {
        return false;
    }
    if (size == 1)
    {
        return true;
    }

    stack<int> valStack;
    int middle = size / 2;
    bool isOddSize = size % 2 != 0;
    Node* curr = head;
    for (int i = 0; i < size; ++i)
    {
        if (i < middle)
        {
            valStack.push(curr->value);
        }
        else if (i == middle && isOddSize)
        {
            // do nothing
        }
        else 
        {
            int val = valStack.top();
            valStack.pop();
            if (val != curr->value)
            {
                return false;
            }
        }

        curr = curr->next;
    }

    return true;
}

int main()
{
    vector<int> vec = {1,0,1,0,1};
    Node* list = vectorToLinkedList(vec);
    bool p = isPalindrome(list, vec.size());
    cout << p;
}
