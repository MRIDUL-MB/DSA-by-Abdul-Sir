#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

node *root = NULL;

void insert(int x)
{
    node *p, *r;
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->left = root->right = NULL;
        root->data = x;
        return;
    }
    p = root;
    while (p)
    {
        r = p;
        if (p->data == x)
        {
            cout << "Already existed " << x << endl;
            return;
        }
        else if (x < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->left = p->right = 0;
    if (x < r->data)
        r->left = p;
    else
        r->right = p;
}

node *insertR(node *p, int x)
{
    node *t;
    if (p == NULL)
    {
        t = (node *)malloc(sizeof(node));
        t->data = x;
        t->left = t->right = 0;
        return t;
    }

    if (x < p->data)
        p->left = insertR(p->left, x);
    else
        p->right = insertR(p->right, x);
    return p;
}

node *search(int x)
{
    node *p = root;
    while (p)
    {
        if (x < p->data)
            p = p->left;
        else if (x > p->data)
            p = p->right;
        else
            return p;
    }
    return NULL;
}

void preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

// void create()
// {
//     int x;
//     node *t, *p;
//     printf("Enter the root element: ");
//     scanf("%d", &x);
//     root = (node*)malloc(sizeof(node));
//     root->left = root->right = 0;
//     root->data = x;
//     p=root;
//     while(p)
//     {
//         printf("Enter the root element: ");
//         scanf("%d", &x);
//         if(p->data == x){
//             cout<<"Already existed"<<endl;
//         }else if(x<p->data){
//             p=p->left;
//         }else{
//             p=p->right;
//         }
//     }

// }

int height(node *p)
{
    if (p == NULL)
        return 0;
    return height(p->left) > height(p->right) ? height(p->left) + 1 : height(p->right) + 1;
}

node *inPre(node *p)
{
    while (p && p->right)
    {
        p = p->right;
    }
    return p;
}
node *inSuc(node *p)
{
    while (p && p->left)
    {
        p = p->left;
    }
    return p;
}

node *del(node *p, int x)
{
    node *q = NULL;
    if (p == NULL)
        return NULL;
    if (!p->left && !p->right)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (x < p->data)
    {
        p->left = del(p->left, x);
    }
    else if (x > p->data)
    {
        p->right = del(p->right, x);
    }
    else
    {
        if (height(p->left) > height(p->right))
        {
            q = inPre(p->left);
            p->data = q->data;
            p->left = del(p->left, q->data);
        }
        else
        {
            q = inSuc(p->right);
            p->data = q->data;
            p->right = del(p->right, q->data);
        }
    }
    return p;
}

int main()
{
    // insert(9);
    // insert(15);
    // insert(5);
    // insert(20);
    // insert(16);
    // insert(8);
    // insert(12);
    // insert(3);
    // insert(6);

    root = insertR(root, 9);
    insertR(root, 15);
    insertR(root, 5);
    insertR(root, 20);
    insertR(root, 16);
    insertR(root, 8);
    insertR(root, 12);
    insertR(root, 3);
    insertR(root, 6);
    preorder(root);
    cout << endl;
    // node *t = search(3);
    root = del(root, 9);
    preorder(root);
}
