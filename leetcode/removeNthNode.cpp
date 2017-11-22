#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    if (head == nullptr || n < 0)
    {
        return nullptr;
    }

    ListNode* curr = head;
    ListNode* runner = head;

    for (int i =0; i < n && runner != nullptr; ++i)
    {
        runner = runner->next;
    }

    // We are assuming n is valid, which means runner is the end of the list.
    // This means we need to remove the head pointer
    if (runner == nullptr)
    {
        head = head->next;
        return head;
    }

    while(runner->next != nullptr)
    {
        curr = curr->next;
        runner = runner->next;
    }

    curr->next = curr->next->next;
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* next = new ListNode(2);

    head->next = next;

    removeNthFromEnd(head, 2);
}