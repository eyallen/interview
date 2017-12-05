#include <iostream>
#include <string>

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

void buildOrderString(TN* node, string& s)
{
    if (node == nullptr)
    {
        s.append("X ");
        return;
    }

    s.append(to_string(node->value) + " ");
    buildOrderString(node->left, s);
    buildOrderString(node->right, s);
}

/*
 * T1 and T2 are very large binary trees, with T1 > T2. Create an algorithm to determine if
 * T2 is a subtree of T1.
 */
bool isSubtree(TN* t1, TN* t2)
{
    string s1;
    buildOrderString(t1, s1);

    string s2;
    buildOrderString(t2, s2);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    return s1.find(s2) != string::npos;
}

int main()
{
    TN* t1 = new TN(0);
    TN* t1L = new TN(-2);
    TN* t1R = new TN(5);
    TN* t1RL = new TN(3);
    TN* t1RR = new TN(7);

    t1->left = t1L;
    t1->right = t1R;

    t1R->left = t1RL;
    t1R->right = t1RR;

    TN* t2 = new TN(5);
    TN* t2L = new TN(3);
    TN* t2R = new TN(7);

    t2->left = t2L;
    t2->right = t2R;

    cout << isSubtree(t1, t2);
}