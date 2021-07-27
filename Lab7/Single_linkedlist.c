// *Written by Aditya Kotwal*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
int Lsearch(int data)
{
    struct node *traverse = head;
    int position = -1;
    int i = 1;
    while (traverse != NULL)
    {
        if (traverse->data == data)
        {
            position = i;
            break;
        }
        i++;
        traverse = traverse->next;
    }
    return position;
}
void insert(int element)
{
    struct node *traverse = head;
    // *IF head node is not present
    if (traverse == NULL)
    {
        traverse = (struct node *)malloc(sizeof(struct node));
        traverse->data = element;
        traverse->next = NULL;
        head = traverse;
    }
    else
    {

        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        // **Now traverse is pointing to last node
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        traverse->next = new_node;
        new_node->data = element;
        new_node->next = NULL;
    }
}
int delete (int element)
{

    int removed = INT_MIN;
    int pos = Lsearch(element);
    if (pos != -1)
    {
        // *Deleting head node(special case cus we need to shift head)
        if (pos == 1)
        {
            struct node *t = head;
            removed = head->data;
            head = head->next;
            free(t);
        }
        else
        {

            struct node *prev = NULL, *next = head;
            while (pos > 1)
            {
                prev = next;
                next = next->next;
                pos--;
            }
            // *NOW next is pointing on a node to be removed
            removed = next->data;
            prev->next = next->next; //NOW recreating links
            free(next);
        }
    }
    return removed;
}

void print()
{

    struct node *traverse = head;
    if (traverse == NULL)
    {
        printf("Empty.\n");
    }
    else
    {

        printf("Now Printing:\n");

        while (traverse != NULL)
        {

            if (traverse->next != NULL)
            {
                printf("|_%d_|->", traverse->data);
            }
            else
            {
                printf("|_%d_|->NULL", traverse->data);
            }

            traverse = traverse->next;
        }
        printf("\n");
    }
}
int main()
{

    int c;
    do
    {
        printf("\nMENU\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Linear Search\n");
        printf("4.Display\n");
        printf("5.Press any other key to Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:;
            int element;
            printf("Enter Element:");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:;
            int el;
            printf("Delete What?\n");
            scanf("%d", &el);
            int x = delete (el);
            if (x != INT_MIN)
            {
                printf("%d Removed.", x);
            }
            else
            {
                printf("No element Like that found");
            }
            break;

        case 3:;
            int e;
            printf("Find What?\n");
            scanf("%d", &e);
            int temp = Lsearch(e);
            if (temp != -1)
            {
                printf("Found at Pos:%d\n", temp);
            }
            else
            {
                printf("Not Found.");
            }
            break;

        case 4:
            print();
            break;
        default:
            printf("------------EXITED------------\n");
            break;
        }
    } while (c < 5 && c >= 1);

    return 0;
}
