#include<iostream>
#include <vector>

namespace datastructures {

template<class T>
struct Node
{
    T value;
    Node* next;

    Node(T val)
    {
        value = val;
        next = nullptr;
    }
};

template <class T>
Node<T>* vectorToLinkedList(std::vector<T> vec)
{
    Node<T>* head = nullptr;
    Node<T>* curr = nullptr;
    for (int i = 0; i < vec.size(); ++i)
    {
        Node<T>* node = new Node<T>(vec[i]);
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

template<class T>
void printLinkedList(Node<T>* head)
{
    Node<T>* curr = head;
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

} // namespace datastructures
