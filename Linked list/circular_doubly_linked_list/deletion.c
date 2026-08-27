#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * next;
    struct node * prev;
};
void traversal(struct node * head)
{
    struct node * temp=head;
    do{
        printf("%d\t",temp->val);
        temp=temp->next;
    }while(temp!=head);
}
int main()
{
    struct node *head=NULL,*tail,*temp,*newnode,*temp1;
    int count=1;
    while(count)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->val);
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("Do u want to add(1/0) : ");
        scanf("%d",&count);
    }
    newnode->next=head;
    head->prev=newnode;
    tail=newnode;
    traversal(head);
    printf("\n*DELETION OF NODE\n\n1)At start\n2)At end\n");
    int yes=1;
    while(yes)
    {
        printf("Enter choice : ");
        scanf("%d",&count);
        if (count == 1)
        {
            temp=head;
            while(temp->next!=head)
                temp=temp->next;
            head=head->next;
            temp->next=head;
            head->prev=temp;
        }
        else{
            temp=head;
            temp1=head->next;
            while(temp1->next!=head)
            {
                temp=temp1;
                temp1=temp1->next;
            }
            temp->next=head;
            head->prev=temp;
            tail=temp;
        }
        traversal(head);
        printf("Do u want to continue :(1/0) : ");
        scanf("%d",&yes);
    }
    return 0;
}