//*Written by Aditya Kotwal
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
void enqueue(int element)
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
int dequeue()
{

    int removed = INT_MIN;
    if (head != NULL)
    {
        struct node *t = head;
        removed = head->data;
        head = head->next;
        free(t);
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
                printf("|_%d_|<-", traverse->data);
            }
            else
            {
                printf("|_%d_|", traverse->data);
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
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Press any other key to Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:;
            int element;
            printf("Enter Element:");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:;
            int x = dequeue();
            if (x != INT_MIN)
            {
                printf("%d dequeued.", x);
            }
            else
            {
                printf("Queue is Empty!");
            }
            break;

        case 3:
            print();
            break;
        default:
            printf("------------EXITED------------\n");
            break;
        }
    } while (c < 4 && c >= 1);

    return 0;
}
