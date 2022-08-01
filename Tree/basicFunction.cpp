#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
class tree
{
public:
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    void create();
    void preorder(node *p);
    void preorderStack(node *p);
    void levelOrder(node *p);
    int count(node *p);
    int countNew(node *p);
};

void tree::create()
{
    node *t, *p;
    queue<node *> q;
    int x;
    cout << "Enter the root value: ";
    cin >> x;
    root = new node;
    root->data = x;
    root->left = root->right = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.push(t);
        }
        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.push(t);
        }
    }
}

void tree::preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void tree::preorderStack(node *p)
{
    stack<node *> s;
    while (p || !s.empty())
    {
        if (p)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void tree::levelOrder(node *p)
{
    queue<node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->left)
        {
            cout << p->left->data << " ";
            q.push(p->left);
        }
        if (p->right)
        {
            cout << p->right->data << " ";
            q.push(p->right);
        }
    }
}

int tree::count(node *p)
{
    if (p)
        return count(p->left) + count(p->right) + 1;
    else
        return 0;
}

int tree::countNew(node *p)
{
    if (p)
    {
        int x = count(p->left);
        int y = count(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    else
        return 0;
}

int main()
{
    tree *t = new tree();
    t->create();
    t->preorder(t->root);
    cout << endl;
    t->preorderStack(t->root);
    cout << endl;
    t->levelOrder(t->root);
    cout << endl;
    cout << t->count(t->root) << endl;
    cout << t->countNew(t->root) << endl;
}