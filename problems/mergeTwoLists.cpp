#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* start = new ListNode(INT_MAX);
    ListNode* tail = start;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    tail->next = l1 != nullptr ? l1 : l2;
    return start->next;
}

ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoListsRecursive(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoListsRecursive(l1, l2->next);
        return l2;
    }
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
    vector<int> l1 = {2, 3};
    vector<int> l2 = {4};

    ListNode* res = mergeTwoLists(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    ListNode* resR = mergeTwoListsRecursive(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(resR) << "\n";

    l1 = {2, 4};
    l2 = {3};

    res = mergeTwoLists(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    resR = mergeTwoListsRecursive(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(resR) << "\n";

    l1 = {};
    l2 = {3, 6, 7};

    res = mergeTwoLists(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    resR = mergeTwoListsRecursive(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(resR) << "\n";

    l1 = {3, 6, 7};
    l2 = {};

    res = mergeTwoLists(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    resR = mergeTwoListsRecursive(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(resR) << "\n";

    l1 = {1, 2, 3};
    l2 = {4, 5, 6};

    res = mergeTwoLists(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(res) << "\n";

    resR = mergeTwoListsRecursive(vectorToListNode(l1), vectorToListNode(l2));
    cout << listNodeToString(resR) << "\n";
}