#include <iostream>
#include <unordered_set>
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

int main()
{
    vector<int> vector = {0,1,2,2,4,5,6,8};
    Node* list = vectorToLinkedList(vector);

    printLinkedList(list);
    removeDuplicates(list);
    printLinkedList(list);
}