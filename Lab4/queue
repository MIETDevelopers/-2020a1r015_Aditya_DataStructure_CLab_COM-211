#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Queue
{
    int Maxsize;
    int front;
    int rear;
    int *data;
};
void create(struct Queue *q, int size)
{
    q->Maxsize = size;
    q->front = q->rear = -1;
    q->data = (int *)malloc(q->Maxsize * sizeof(int));
}
void enqueue(struct Queue *q, int x)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = x;
    }
    else if ((q->rear + 1) % q->Maxsize == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->Maxsize;
        q->data[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = INT_MIN;
    if (q->front == -1 && q->rear == -1)
    {
        printf("Underflow!!\n");
    }
    else if (q->front == q->rear)
    {

        x = q->data[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        x = q->data[q->front];
        q->front = (q->front + 1) % q->Maxsize;
    }
    return x;
}
void Display(struct Queue q)
{
    int i = q.front;
    if (q.front == -1 && q.rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        do
        {

            printf("%d ", q.data[i]);
            i = (i + 1) % q.Maxsize;
        } while (i != (q.rear + 1) % q.Maxsize);

        printf("\n");
    }
}
int main()
{
    struct Queue q;
    int size;
    printf("Enter Max size:");
    scanf("%d", &size);
    //**no need to use this cuz compiler automatically makes INT_MAX+1=INT_MIN(i.e int values will range in between them)
    //**BUT i still didnt commented if thisthing doesnt runs for some compilers;)
    if (size >= INT_MAX || size <= INT_MIN)
    {
        printf("Max Limit for Integer Exceeded!!\nTry Again!!\n");
        return 0;
    }

    create(&q, size);
    int choice;
    do
    {
        printf("MENU:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Print QueueA\n");
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:;
            int x;
            printf("Enter element:");
            scanf("%d", &x);
            if (x > INT_MAX || x < INT_MIN)
            {
                printf("Max Limit for Integer Exceeded!!\nTry Again!!\n");
                break;
            }
            enqueue(&q, x);
            break;
        case 2:;
            int temp = dequeue(&q);
            if (temp != INT_MIN)
            {
                printf("Succesfully dequeued :%d\n", temp);
            }
            break;
        case 3:
            Display(q);
            break;

        default:
            printf("Wrong Choice:(\n");
            break;
        }
    } while (choice < 4 && choice > 0);

    return 0;
}
