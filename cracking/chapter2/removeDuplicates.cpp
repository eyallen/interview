#include "../../datastructures/linkedList.h"
#include <unordered_set>

using namespace std;
using namespace datastructures;

void removeDuplicates(Node<int>* head)
{
    unordered_set<int> uniqueValues;
    Node<int>* prev = nullptr;
    Node<int>* curr = head;

    while(curr != nullptr)
    {
        if (uniqueValues.find(curr->value) != uniqueValues.end())
        {
            prev->next = curr->next;
            Node<int>* toDel = curr;
            curr = curr->next;
            delete toDel;
        }
        else
        {
            uniqueValues.insert(curr->value);
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    vector<int> vector = {0,1,2,2,4,5,6,8};
    Node<int>* list = vectorToLinkedList(vector);

    printLinkedList(list);
    removeDuplicates(list);
    printLinkedList(list);
}