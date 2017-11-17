#include "../../datastructures/linkedList.h"

using namespace std;
using namespace datastructures;

Node<int>* appendValueToList(Node<int>* head, int value)
{
    Node<int>* node = new Node(value);
    if (head == nullptr)
    {
        return node;
    }

    Node<int>* curr = head;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = node;
    return head;
}

Node<int>* partitionLinkedList(Node<int>* head, int pivot)
{
    Node<int>* lt = nullptr;
    Node<int>* gt = nullptr;
    Node<int>* curr = head;
    
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

    Node<int>* ltTail = lt;
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

    Node<int>* list = vectorToLinkedList(vec);
    list = partitionLinkedList(list, 5);
    printLinkedList(list);

    list = partitionLinkedList(list, 2);
    printLinkedList(list);

    list = partitionLinkedList(list, 3);
    printLinkedList(list);

    list = partitionLinkedList(list, 7);
    printLinkedList(list);
}