#include "linkedListHelpers.h"

using namespace std;

Node* appendValueToList(Node* head, int value)
{
    Node* node = new Node(value);
    if (head == nullptr)
    {
        return node;
    }

    Node* curr = head;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = node;
    return head;
}

Node* partitionLinkedList(Node* head, int pivot)
{
    Node* lt = nullptr;
    Node* gt = nullptr;
    Node* curr = head;
    
    while(curr != nullptr)
    {
        if (curr->value < pivot)
        {
            lt = appendValueToList(lt, curr->value);
        }
        else
        {
            gt = appendValueToList(gt, curr->value);
        }
        curr = curr->next;
    }

    // Now merge the lists together
    if (lt == nullptr)
    {
        return gt;
    }
    if (gt == nullptr)
    {
        return lt;
    }

    Node* ltTail = lt;
    while(ltTail->next != nullptr)
    {
        ltTail = ltTail->next;
    }

    ltTail->next = gt;
    return lt;
}

int main()
{
    vector<int> vec = {3,5,8,5,10,2,1};

    Node* list = vectorToLinkedList(vec);
    list = partitionLinkedList(list, 5);
    printLinkedList(list);

    list = partitionLinkedList(list, 2);
    printLinkedList(list);

    list = partitionLinkedList(list, 3);
    printLinkedList(list);

    list = partitionLinkedList(list, 7);
    printLinkedList(list);
}