#include "../../datastructures/linkedList.h"

using namespace std;
using namespace datastructures;

Node<int>* detectLoop(Node<int>* head)
{
    Node<int>* faster = head;
    Node<int>* slower = head;

    while (faster != nullptr && faster->next != nullptr)
    {
        faster = faster->next->next;
        slower = slower->next;

        if (faster == slower)
        {
            break;
        }
    }

    // If we didn't find a loop, return
    if (faster == nullptr || faster->next == nullptr)
    {
        return nullptr;
    }

    slower = head;
    while (faster != slower)
    {
        faster = faster->next;
        slower = slower->next;
    }

    // The two nodes should now be at the start of the loop
    return faster;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8};
    Node<int>* head = vectorToLinkedList(vec);

    Node<int>* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Node 5
    tail->next = head->next->next->next->next;

    Node<int>* loopStart = detectLoop(head);
    cout << loopStart->value << endl;

    // Node 7
    tail->next = head->next->next->next->next->next->next;

    loopStart = detectLoop(head);
    cout << loopStart->value << endl;
}