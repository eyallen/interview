#include "linkedListHelpers.h"

using namespace std;

int main()
{
    vector<int> vec = {10,1,2,4,5,8,7};
    Node* list = vectorToLinkedList(vec);
    printLinkedList(list);
}