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
void InsertTree(int x)
{
    struct node *next = root, *prev = NULL;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->left = new_node->right = NULL;
    new_node->data = x;
    while (next != NULL)
    {
        prev = next;
        if (x == next->data)
        {
            printf("Get Lost!!\n");
            return;
        }
        else if (x < next->data)
        {
            next = next->left;
        }
        else
        {
            next = next->right;
        }
    }
    if (x > prev->data)
    {
        prev->right = new_node;
    }
    else
    {
        prev->left = new_node;
    }
}
struct node *search(struct node *p, int data)
{

    if (p == NULL)
    {
        return NULL;
    }
    if ((p->left != NULL && p->left->data == data) || (p->right != NULL && p->right->data == data))
    {
        return p;
    }
    struct node *l = search(p->left, data);
    if (l)
    {
        return l;
    }
    struct node *r = search(p->right, data);
    if (r)
    {
        return r;
    }
    return NULL;
}
void dlt(struct node *parent, struct node *toBedeleted)
{
    if (toBedeleted->left == NULL && toBedeleted->right == NULL)
    {
        //leaf node
        if (toBedeleted == root)
        {
            free(root);
            root = NULL;
        }
        else if (parent->left == toBedeleted)
        {
            parent->left = NULL;
        }
        else if (parent->right == toBedeleted)
        {
            parent->right = NULL;
        }
        free(toBedeleted);
    }
    else if (toBedeleted->left != NULL && toBedeleted->right != NULL)
    {
        //2child now finding successor
        struct node *lparent = toBedeleted;
        struct node *l = lparent->left;
        printf("parent:%d\n", lparent->data);
        while (l->right != NULL)
        {
            lparent = l;
            l = l->right;
        }
        //now l is pointing to child lsubtree max elemnt
        toBedeleted->data = l->data;
        dlt(lparent, l);
    }
    else
    {
        // for one child
        if (parent->left == toBedeleted)
        {

            if (toBedeleted->right == NULL)
            {
                parent->left = toBedeleted->left;
            }
            else
            {

                parent->left = toBedeleted->right;
            }
        }
        else
        {

            if (toBedeleted->left == NULL)
            {
                parent->right = toBedeleted->right;
            }
            else
            {

                parent->right = toBedeleted->left;
            }
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
        printf("%d ", p->data);
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
                int x;
                printf("Enter element:\n");
                scanf("%d", &x);
                InsertTree(x);
            }
        }
        else if (c == 2)
        {
            int key;
            printf("Enter element:\n");
            scanf("%d", &key);
            struct node *parent;
            parent = search(root, key);
            if (root->data == key)
            {
                parent = root;
                dlt(NULL, parent);
            }
            else if (parent == NULL)
            {
                printf("Not Found");
            }
            else if (parent->left != NULL && parent->left->data == key)
            {
                dlt(parent, parent->left);
            }
            else
            {
                dlt(parent, parent->right);
            }
        }

        else if (c == 3)
        {
            int key;
            printf("Search what?\n");
            scanf("%d", &key);
            if (root->data == key)
            {
                printf("Its's Root lol!\n");
            }
            else
            {
                struct node *t = search(root, key);
                if (t == NULL)
                {
                    printf("Not Found\n");
                }
                else
                {
                    printf("Found\n");
                }
            }
        }
        else if (c == 4)
        {
            printf("preorder:\n");
            preorder(root);
        }
        else if (c == 5)
        {
            printf("Inorder:\n");
            inorder(root);
        }
        else if (c == 6)
        {
            printf("PostOrder:\n");
            postorder(root);
        }

    } while (c <= 6);

    return 0;
}
