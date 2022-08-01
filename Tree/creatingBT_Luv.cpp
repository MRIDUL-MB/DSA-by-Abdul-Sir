#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

node *createBT(node *root)
{
    int x;
    cout << "Enter the data: ";
    cin >> x;
    root = new node(x);

    if (x == -1)
        return NULL;
    cout << "Enter the left Element of " << x << endl;
    root->left = createBT(root->left);
    cout << "Enter the right Element of " << x << endl;
    root->right = createBT(root->right);

    return root;
}

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        cout << t->data << " ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
}

// this is for priting like tree structure
// void levelOrder(node *root)
// {
//     queue<node *> q;
//     q.push(root);
//     q.push(NULL); // for breakpoint we are inserting null
//     while (!q.empty())
//     {
//         node *t = q.front();
//         q.pop();

//         // breakpoint
//         if (t == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << t->data << " ";
//             if (t->left)
//                 q.push(t->left);
//             if (t->right)
//                 q.push(t->right);
//         }
//     }
// }

void createFromLevelOrder(node *&root)
{
    queue<node *> q;
    int x;
    cout << "Enter the root data: ";
    cin >> x;
    root = new node(x);
    q.push(root);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        cout << "Enter Left element of " << t->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t->left = new node(x);
            q.push(t->left);
        }
        cout << "Enter Right element of " << t->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t->right = new node(x);
            q.push(t->right);
        }
    }
}

int main()
{
    node *root = NULL;
    // root = createBT(root);
    createFromLevelOrder(root);
    // 30 20 10 -1 15 -1 -1 25 -1 -1 40 -1 100 45 -1 -1 -1
    cout << "Level Order Transversal: " << endl;
    levelOrder(root);
}