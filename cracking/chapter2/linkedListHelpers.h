#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    int value;
    Node* next;

    Node(int val)
    {
        value = val;
    }
};

Node* vectorToLinkedList(vector<int> vec)
{
    Node* head = nullptr;
    Node* curr = nullptr;
    for (int i = 0; i < vec.size(); ++i)
    {
        Node* node = new Node(vec[i]);
        if (head == nullptr)
        {
            head = node;
            curr = head;
        }
        else 
        {
            curr->next = node;
            curr = node;
        }
    }

    return head;
}

void printLinkedList(Node* head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->value;
        if (curr->next != nullptr) 
        {
            cout << "->";
        }
        curr = curr->next;
    }
    cout << endl;
}