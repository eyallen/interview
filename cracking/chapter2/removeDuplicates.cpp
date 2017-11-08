#include "linkedListHelpers.h"
#include <unordered_set>

using namespace std;

void removeDuplicates(Node* head)
{
    unordered_set<int> uniqueValues;
    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr)
    {
        if (uniqueValues.find(curr->value) != uniqueValues.end())
        {
            prev->next = curr->next;
            Node* toDel = curr;
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
    Node* list = vectorToLinkedList(vector);

    printLinkedList(list);
    removeDuplicates(list);
    printLinkedList(list);
}