#include "../../datastructures/linkedList.h"
#include <cmath>

using namespace std;
using namespace datastructures;

bool areIntersecting(Node<int>* a, Node<int>* b, Node<int>** intersecting)
{
    if (a == nullptr || b == nullptr)
    {
        return false;
    }

    Node<int>* currA = a;
    Node<int>* currB = b;
    int sizeA = 1;
    int sizeB = 1;

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
        Node<int>* longer = sizeA > sizeB ? a : b;
        Node<int>* shorter = sizeA > sizeB ? b : a;

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

    Node<int>* listA = vectorToLinkedList(vecA);
    Node<int>* listB = vectorToLinkedList(vecB);

    Node<int>* inter1;
    cout << areIntersecting(listA, listB, &inter1) << endl;

    Node<int>* one = new Node<int>(1);
    Node<int>* two = new Node<int>(2);
    Node<int>* three = new Node<int>(3);
    Node<int>* four = new Node<int>(4);
    Node<int>* five = new Node<int>(5);

    one->next = two;
    two->next = three;
    four->next = two;
    five->next = four;

    Node<int>* inter2;
    cout << areIntersecting(one, five, &inter2) << " " << inter2->value << endl;
}