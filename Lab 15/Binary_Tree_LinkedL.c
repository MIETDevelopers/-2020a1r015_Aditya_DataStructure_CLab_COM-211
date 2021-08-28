#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;
struct queue
{
    struct node **Q;
    int front;
    int rear;
    int maxsize;
};
void createQ(struct queue *q, int size)
{
    q->Q = (struct node **)malloc(sizeof(struct node *) * size);
    q->front = -1;
    q->rear = -1;
    q->maxsize = size;
}
void enqueue(struct queue *q, struct node *p)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->Q[q->rear] = p;
    }
    else if ((q->rear + 1) % q->maxsize == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->maxsize;
        q->Q[q->rear] = p;
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *t = NULL;
    if (q->front == -1 && q->rear == -1)
    {
        printf("Underflow!!\n");
    }
    else if (q->front == q->rear)
    {

        t = q->Q[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {

        t = q->Q[q->front];
        q->front = (q->front + 1) % q->maxsize;
    }
    return t;
}
bool ifEmp(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return true;
    }
    return false;
}
void InsertTree(int parent, int element, char choice)
{
    struct queue q;
    createQ(&q, 200);
    enqueue(&q, root);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->left = new_node->right = NULL;
    new_node->data = element;
    while (!ifEmp(&q))
    {
        struct node *out = dequeue(&q);
        if (out->data == parent)
        {
            if (out->left == NULL && choice == 'l')
            {
                out->left = new_node;
            }
            else if (out->right == NULL && choice == 'r')
            {
                out->right = new_node;
            }
            else
            {
                printf("Already Present\n\n");
            }
            return;
        }

        if (out->left != NULL)
        {
            enqueue(&q, out->left);
        }
        if (out->right != NULL)
        {

            enqueue(&q, out->right);
        }
    }
    printf("\n\nNO such parent(%d) found\n\n", parent);
}
void dLast(struct node *last)
{
    struct queue q;
    createQ(&q, 200);
    enqueue(&q, root);
    struct node *traverse = NULL;
    while (!ifEmp(&q))
    {
        traverse = dequeue(&q);
        if (traverse == last)
        {
            traverse = NULL;
            free(last);
            return;
        }
        if (traverse->left != NULL)
        {
            if (traverse->left == last)
            {
                traverse->left = NULL;
                free(last);
                return;
            }
            else
            {
                enqueue(&q, traverse->left);
            }
        }
        if (traverse->right != NULL)
        {
            if (traverse->right == last)
            {
                traverse->right = NULL;
                free(last);
                return;
            }
            else
            {
                enqueue(&q, traverse->right);
            }
        }
    }
}
void d(int e)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->right == NULL && root->left == NULL && root->data == e)
    {
        root = NULL;
        return;
    }
    else
    {
        struct queue q;
        createQ(&q, 200);
        enqueue(&q, root);
        struct node *last, *tobeDeleted = NULL;
        struct node *traverse;
        while (!ifEmp(&q))
        {
            traverse = dequeue(&q);
            last = traverse;
            if (traverse->data == e)
            {
                tobeDeleted = traverse;
            }
            if (traverse->left != NULL)
            {
                enqueue(&q, traverse->left);
            }
            if (traverse->right != NULL)
            {
                enqueue(&q, traverse->right);
            }
        }
        // now we found the rightmost deepest node(last) && node that needs to be deleted(tobeDeleted)
        if (tobeDeleted != NULL)
        {
            tobeDeleted->data = last->data;
            // now we need to find parent of last node
            dLast(last);
        }
    }
}
void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(struct node *p)
{

    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", root->data);
        inorder(p->right);
    }
}
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}
bool search(struct node *p, int data)
{
    if (p == NULL)
    {
        return false;
    }
    if (p->data == data)
    {
        return true;
    }
    bool l = search(p->left, data);
    if (l)
    {
        return true;
    }
    bool r = search(p->right, data);
    if (r)
    {
        return true;
    }
    return false;
}
int main()
{
    int c;
    do
    {
        printf("\n\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.preorder\n");
        printf("5.Inorder\n");
        printf("6.Postorder\n");
        scanf("%d", &c);
        if (c == 1)
        {
            if (root == NULL)
            {
                root = (struct node *)malloc(sizeof(struct node));
                root->left = root->right = NULL;
                printf("Enter root value:\n");
                scanf("%d", &root->data);
            }
            else
            {
                int parent, child;
                char LorR;
                printf("Enter parent,child and L||R:\n");
                scanf("%d%d", &parent, &child);
                scanf(" %c", &LorR);
                InsertTree(parent, child, LorR);
            }
        }
        else if (c == 2)
        {
            int key;
            printf("Enter element:\n");
            scanf(" %d", &key);
            d(key);
        }

        else if (c == 3)
        {
            int key;
            printf("Search what?\n");
            scanf("%d", &key);
            if (search(root, key))
            {
                printf("Found\n");
            }
            else
            {
                printf("Not found\n");
            }
        }
        else if (c == 4)
        {

            preorder(root);
        }
        else if (c == 5)
        {
            inorder(root);
        }
        else if (c == 6)
        {
            postorder(root);
        }

    } while (c <= 6);

    return 0;
}
