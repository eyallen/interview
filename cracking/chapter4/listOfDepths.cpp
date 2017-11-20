#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TN
{
    int value;
    TN* left;
    TN* right;

    TN(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

struct LL
{
    TN* node;
    LL* next;

    LL(TN* n)
    {
        node = n;
        next = nullptr;
    }
};

LL* linkedListFromQueue(queue<TN*>& q1, queue<TN*>& q2)
{
    LL* list = nullptr;

    while(!q1.empty())
    {
        TN* r = q1.front();
        q1.pop();

        LL* l = new LL(r);
        l->next = list;
        list = l;

        if (r->left != nullptr)
        {
            q2.push(r->left);
        }
        if (r->right != nullptr)
        {
            q2.push(r->right);
        }
    }

    return list;
}

vector<LL*> listOfDepths(TN* root)
{
    vector<LL*> list = vector<LL*>();
    if (root == nullptr)
    {
        return list;
    }

    queue<TN*> q1 = queue<TN*>();
    queue<TN*> q2 = queue<TN*>();

    q1.push(root);
    while (!q1.empty() || !q2.empty())
    {
        LL* l1 = linkedListFromQueue(q1,q2);
        LL* l2 = linkedListFromQueue(q2,q1);

        if (l1 != nullptr)
        {
            list.push_back(l1);
        }

        if (l2 != nullptr)
        {
            list.push_back(l2);
        }
    }

    return list;
}

int main()
{
    TN* root = new TN(1);
    TN* l1 = new TN(2);
    TN* l1l1 = new TN(3);
    TN* l1r1 = new TN(5);
    TN* r1 = new TN(6);
    TN* r1l1 = new TN(7);
    TN* r1r1 = new TN(8);

    root->left = l1;
    root->right = r1;
    l1->left = l1l1;
    l1->right = l1r1;
    r1->left = r1l1;
    r1->right = r1r1;

    vector<LL*> depths = listOfDepths(root);
    cout << depths.size() << endl;
}
