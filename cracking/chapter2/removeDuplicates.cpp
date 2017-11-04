#include <iostream>
#include <unordered_set>

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

int main()
{
    Node* one = new Node(0);
    Node* two = new Node(1);
    Node* three = new Node(2);
    Node* four = new Node(2);
    Node* five = new Node(3);
    Node* six = new Node(4);
    Node* seven = new Node(5);
    Node* eight = new Node(1);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nullptr;

    removeDuplicates(one);
}