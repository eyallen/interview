#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    ListNode(int x) : 
        val(x),
        next(nullptr)
    {
    }

    int val;
    ListNode* next;
};

/*
 * Given two non-empty linked lists representing two non-negative integers (stored)
 * in reverse order), add the two numbers and return a linked list.
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* head = new ListNode(0);
    ListNode* result = head;

    ListNode* p1 = l1;
    ListNode* p2 = l2;

    int remainder = 0;

    while (p1 != nullptr || p2 != nullptr)
    {
        int val1 = (p1 != nullptr) ? p1->val : 0;
        int val2 = (p2 != nullptr) ? p2->val : 0;

        int value = (val1 + val2 + remainder) % 10;
        remainder = (val1 + val2 + remainder) >= 10 ? 1 : 0;

        head->next = new ListNode(value);
        head = head->next;

        if (p1 != nullptr)
        {
            p1 = p1->next;
        }

        if (p2 != nullptr)
        {
            p2 = p2->next;
        }
    }

    if (remainder != 0)
    {
        head->next = new ListNode(1);
    }

    return result->next;
}

ListNode* vectorToListNode(vector<int> list) 
{
    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) 
{
    string result;
    if (node == nullptr) {
        return result;
    }

    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return result.substr(0, result.length() - 2);
}

int main()
{
    vector<int> l1 = {2,4,3};
    vector<int> l2 = {5, 6, 4};

    ListNode* res = addTwoNumbers(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    l1 = {0,1};
    l2 = {0, 1, 2};

    res = addTwoNumbers(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    l1 = {0,1};
    l2 = {};

    res = addTwoNumbers(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    l1 = {9,9};
    l2 = {1};

    res = addTwoNumbers(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";
}