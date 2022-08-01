#include <stdio.h>
#include <stdlib.h>

// tree structure
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;
tree *root;

// queue structure
typedef struct queue
{
    int size;
    int front;
    int rear;
    tree **arr;
} queue;
queue q;

// queue methods......
void createQueue(int size)
{
    q.arr = (tree **)malloc(sizeof(tree *) * size);
    q.front = q.rear = 0;
    q.size = size;
}

int isFull()
{
    if ((q.rear + 1) % q.size == q.front)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (q.rear == q.front)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(tree *val)
{
    if (isFull())
        printf("Queue is Full\n");
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.arr[q.rear] = val;
        // printf("at index %d, value %d pushed in...\n", q.rear, val);
    }
}
tree *dequeue()
{
    tree *x = NULL;
    if (isEmpty())
        printf("Queue is Empty\n");
    else
    {
        q.front = (q.front + 1) % q.size;
        x = q.arr[q.front];
        // printf("at index %d, value %d is deleted ...\n", q.front, x);
    }
    return x;
}

// tree methods......
void createTree()
{
    tree *temp, *p;
    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (tree *)malloc(sizeof(tree));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(root);
    while (!isEmpty())
    {
        p = dequeue();
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (tree *)malloc(sizeof(tree));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->left = temp;
            enqueue(temp);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (tree *)malloc(sizeof(tree));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->right = temp;
            enqueue(temp);
        }
    }
}

void preorder(tree *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(tree *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
void postorder(tree *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}
int main()
{
    // queue is ok
    createQueue(70);
    createTree();
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
}