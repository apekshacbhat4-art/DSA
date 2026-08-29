#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * next;
};
struct node * head=0;
void push(struct node * newnode)
{
    newnode->next=head;
    head=newnode;
}
int pop()
{
    int val=head->val;
    head=head->next;
    return val;
}
int peek()
{
    return head->val;
}
int isEmpty()
{
    if(head==0)
    return 1;
    return 0;
}
int len()
{
    int size=0;
    struct node * temp=head;
    while(temp!=0)
    {
        temp=temp->next;
        size++;
    }
    return size;
}
void display()
{
    struct node*temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }
}
void clear()
{
    head=0;
}
void main()
{
    struct node * newnode;
    printf("**STACK OPERATIONS**\n\n");
    printf("1)push()\n2)pop()\n3)peek()\n4)display()\n5)isEmpty()\n6)clear()\n7)size()\n");
    int choice,yes=1,empty;
    while(yes)
    {
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            newnode= (struct node * )malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d",&newnode->val);
            push(newnode);
            break;
            case 2:
            empty=isEmpty();
            if(empty==1)
            printf("Empty stack\n");
            else
            printf("Popped value : %d\n",pop());
            break;
            case 3:
            empty=isEmpty();
            if(empty==1)
            printf("Empty stack\n");
            else
            printf("Top value : %d\n",peek());
            break;
            case 4:
            display();
            break;
            case 5:
            empty=isEmpty();
            if(empty==1)
            printf("Empty stack\n");
            else
            printf("Stack is not empty\n");
            break;
            case 6:
            clear();
            break;
            case 7:
            printf("Size of stack : %d\n",len());
            break;

        }
        printf("\n\nDo u want to continue: (1/0) :");
        scanf("%d",&yes);
    }
}