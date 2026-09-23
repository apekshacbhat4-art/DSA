#define size 4
#include<stdio.h>
#include<stdlib.h>
int queue[size],rear=-1,front=0;
int isEmpty()
{
    if(front>rear)
    {
        front=0;
        rear=-1;
        return 1;
    }
    return 0;
}
int isFull()
{
    if(rear==size-1)
    return 1;
    return 0;
}
int peek()
{
    return queue[front];
}
void enqueue(int val)
{
    queue[++rear]=val;
}
int dequeue()
{
    return queue[front++];
}
void display()
{
    for(int i=front;i<=rear;i++)
    printf("%d\t",queue[i]);
}
void main()
{
    printf("\n\nMENU OPTIONS\n\n1)enqueue\n2)dequeue\n3)display\n4)peek\n5)isEmpty\n6)isFull\n7)exit\n");
    int val,choice;
    while(1)
    {
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to insert : ");
            scanf("%d",&val);
            if(isFull())
            printf("Overflow condition");
            else
            enqueue(val);
            break;
            case 2:
            if(isEmpty())
            printf("Underflow condition");
            else
            printf("Deleted element : %d",dequeue());
            break;
            case 3:
            if(isEmpty())
            printf("Empty queue");
            else
            display();
            break;
            case 4:
            if(isEmpty())
            printf("Empty queue");
            else
            printf("Front element : %d",peek());
            break;
            case 5:
            if(isEmpty())
            printf("Empty queue");
            else
            printf("Non empty queue");
            break;
            case 6:
            if(isFull())
            printf("Full queue");
            else
            printf("Not full queue");
            break;
            case 7:
            exit(0);
        }
    }
}