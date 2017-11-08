#include "linkedListHelpers.h"
#include <vector>

using namespace std;

void deleteMiddleNode(Node* toDelete)
{
    if (toDelete == nullptr || toDelete->next == nullptr)
    {
        return;
    }

    Node* next = toDelete->next;
    toDelete->value = next->value;
    toDelete->next = next->next;
    delete next;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    Node* list = vectorToLinkedList(vec);
    deleteMiddleNode(list->next);
    printLinkedList(list);
}