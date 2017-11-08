#include "linkedListHelpers.h"

using namespace std;

Node* findKthToLastElement(Node* head, int k)
{
    Node* kth = head;
    Node* curr = head;

    for (int i = 0; i < k && kth != nullptr; i++)
    {
        kth = kth->next;
    }

    if (kth == nullptr)
    {
        return nullptr;
    }

    while (kth->next != nullptr)
    {
        kth = kth->next;
        curr = curr->next;
    }

    return curr;
}

int main()
{
    vector<int> vec = {10,9,8,7,6,5,4,3,2,1,0};
    Node* list = vectorToLinkedList(vec);
    Node* kth = findKthToLastElement(list, 0);
    cout << kth->value << endl;

    kth = findKthToLastElement(list, 5);
    cout << kth->value << endl;

    return 0;
}