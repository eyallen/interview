#include <vector>
#include "../../datastructures/linkedList.h"

using namespace std;
using namespace datastructures;

void deleteMiddleNode(Node<int>* toDelete)
{
    if (toDelete == nullptr || toDelete->next == nullptr)
    {
        return;
    }

    Node<int>* next = toDelete->next;
    toDelete->value = next->value;
    toDelete->next = next->next;
    delete next;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    Node<int>* list = vectorToLinkedList(vec);
    deleteMiddleNode(list->next);
    printLinkedList(list);
}