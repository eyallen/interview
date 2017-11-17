#include "../../datastructures/linkedList.h"
#include <iostream>
#include <stack>

using namespace std;
using namespace datastructures;

// 1->2->1

// When we don't know the length
bool isPalindrome(Node<int>* head)
{
    stack<int> valStack;
    Node<int>* slow = head;
    Node<int>* fast = head;

    while (slow != nullptr && fast->next != nullptr)
    {
        valStack.push(slow->value);
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != nullptr)
    {
        // Ignore the middle element in odd sized lists
        slow = slow->next;
    }

    while(slow != nullptr)
    {
        int val = valStack.top();
        valStack.pop();

        if (val != slow->value)
        {
            return false;
        }

        slow = slow->next;
    }

    return true;
}

// When we know the length
bool isPalindrome(Node<int>* head, int size)
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
    Node<int>* curr = head;
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

bool isPalindromRecursive(Node<int>* head, int length, Node<int>** res)
{
    if (head == nullptr || length <= 0)
    {
        *res = head;
        return true;
    }
    if (length == 1)
    {
        *res = head->next;
        return true;
    }

    Node<int>* result;
    bool isPal = isPalindromRecursive(head->next, length-2,&result);

    if (!isPal || result == nullptr)
    {
        return isPal;
    }

    *res = result->next;
    return head->value == result->value;
}

bool isPalindromeR(Node<int>* head, int length)
{
    Node<int>* n;
    return isPalindromRecursive(head,length,&n);
}

int main()
{
    vector<int> vec = {1,0,1,0,1};
    Node<int>* list = vectorToLinkedList(vec);
    
    cout << isPalindrome(list, 5) << endl;
    cout << isPalindromeR(list, 5) << endl;
    cout << isPalindrome(list) << endl;

    vec = {1,2,1,0,1};
    list = vectorToLinkedList(vec);
    
    cout << isPalindrome(list, 5) << endl;
    cout << isPalindromeR(list, 5) << endl;
    cout << isPalindrome(list) << endl;
}
