#include "linkedListHelpers.h"
#include <cmath>

using namespace std;

bool areIntersecting(Node* a, Node* b, Node** intersecting)
{
    if (a == nullptr || b == nullptr)
    {
        return false;
    }

    Node* currA = a;
    Node* currB = b;
    int sizeA = 0;
    int sizeB = 0;

    while(currA->next != nullptr)
    {
        sizeA++;
        currA = currA->next;
    }

    while(currB->next != nullptr)
    {
        sizeB++;
        currB = currB->next;
    }

    bool intersect = currA == currB;
    if (intersect)
    {
        Node* longer = sizeA > sizeB ? a : b;
        Node* shorter = sizeA > sizeB ? b : a;

        int sizeDiff = abs(sizeA - sizeB);
        for (int i = 0; i < sizeDiff; i++)
        {
            longer = longer->next;
        }

        while(longer != nullptr && shorter != nullptr)
        {
            if (longer == shorter)
            {
                *intersecting = longer;
                break;
            }
            longer = longer->next;
            shorter = shorter->next;
        }
    }

    return intersect;
}

int main()
{
    vector<int> vecA = {1,2,3,4};
    vector<int> vecB = {1,2,3};

    Node* listA = vectorToLinkedList(vecA);
    Node* listB = vectorToLinkedList(vecB);

    Node* inter1;
    cout << areIntersecting(listA, listB, &inter1) << endl;

    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);

    one->next = two;
    two->next = three;
    four->next = two;

    Node* inter2;
    cout << areIntersecting(one, four, &inter2) << " " << inter2->value << endl;
}