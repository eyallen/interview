#include <iostream>
#include <vector>

struct Node 
{
    int value;
    Node* next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

Node* vectorToLinkedList(std::vector<int> vec)
{
    Node* head = nullptr;
    Node* curr = nullptr;
    for (int i = 0; i < vec.size(); ++i)
    {
        Node* node = new Node(vec[i]);
        if (head == nullptr)
        {
            head = node;
            curr = node;
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
        std::cout << curr->value;
        if (curr->next != nullptr) 
        {
            std::cout << "->";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}