#include "../../datastructures/linkedList.h"

using namespace std;
using namespace datastructures;

Node<int>* findKthToLastElement(Node<int>* head, int k)
{
    Node<int>* kth = head;
    Node<int>* curr = head;

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
    Node<int>* list = vectorToLinkedList(vec);
    Node<int>* kth = findKthToLastElement(list, 0);
    cout << kth->value << endl;

    kth = findKthToLastElement(list, 5);
    cout << kth->value << endl;

    return 0;
}