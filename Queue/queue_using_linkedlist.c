#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * front=0,*rear=0;
void enqueue(int val)
{
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(rear==0 || front==0)
    {
        rear=front=newnode;
        rear->next=0;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=0;
    }  
}
int isEmpty()
{
    if(front==0 || rear==0)
    return 1;
    return 0;
}
void dequeue()
{
    if(front==0)
    {
        printf("Underflow condition");
        rear=0;
        return;
    }
    printf("Deleted element:%d",front->data);
    if(front->next!=0)
    front=front->next;
    else 
    front=0;
}
int peek()
{
    return front->data;
}
void display()
{
    struct node * temp=front;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void main()
{
    printf("MENU OPTIONS\n1)enqueue\n2)dequeue\n3)display\n4)peek\n5)isEmpty\n6)exit\n\n");
    int val,choice;
    while(1)
    {
        printf("\n\nEnter choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to insert : ");
            scanf("%d",&val);
            enqueue(val);
            break;
            case 2:
            dequeue();
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
            printf("Not empty queue");
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    
    
}