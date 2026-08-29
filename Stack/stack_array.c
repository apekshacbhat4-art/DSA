#define N 5
#include<stdio.h>
int stack[N];
int temp=-1;
void push(int val)
{
    if(temp==N-1)
    printf("Stack is full\n");
    else
    stack[++temp]=val;
}
int isEmpty()
{
    if(temp==-1)
    return 1;
    return 0;
}
int pop()
{
    return stack[temp--];
}
void display()
{
    int k=temp;
    while(k!=-1)
    printf("%d\t",stack[k--]);
}
int peek()
{
    return stack[temp];
}
int isFull()
{
    if(temp==N-1)
    return 1;
    return 0;
}
void clear()
{
    temp=-1;
}
int size()
{
    return temp+1;
}
void main()
{
    printf("**STACK OPERATIONS**\n\n");
    printf("1)push()\n2)pop()\n3)peek()\n4)display()\n5)isEmpty()\n6)isFull()\n7)clear()\n8)size()\n");
    int choice,yes=1,val,empty,full;
    while(yes)
    {
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter value: ");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            empty=isEmpty();
            if(empty==1)
            printf("Stack is empty\n");
            else
            printf("Popped value :%d\n",pop());
            break;
            case 3:
            empty=isEmpty();
            if(empty==1)
            printf("Stack is empty\n");
            else
            printf("Top value :%d\n",peek());
            break;
            case 4:
            display();
            break;
            case 5:
            empty=isEmpty();
            if(empty==1)
            printf("Stack is empty\n");
            else
            printf("Stack is not empty\n");
            break;
            case 6:
            full=isFull();
            if(full==1)
            printf("Stack is full\n");
            else
            printf("Stack is not full\n");
            break;
            case 7:
            clear();
            break;
            default:
            printf("Number of elements in stack:%d\n",size());
        }
        printf("\n\nDo u want to continue: (1/0) :");
        scanf("%d",&yes);
    }
}