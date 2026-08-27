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
    struct node *head=NULL,*tail,*temp,*newnode;
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
    printf("\n*INSERTION OF NODE\n\n1)At start\n2)At end\n");
    int yes=1;
    while(yes)
    {
        newnode=(struct node * )malloc(sizeof(struct node));
        printf("Enter new data :");
        scanf("%d",&newnode->val);
        printf("Enter choice : ");
        scanf("%d",&count);
        if (count == 1)
        {
            temp=head;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=newnode;
            head->prev=newnode;
            newnode->next=head;
            newnode->prev=temp;
            head=newnode;
        }
        else{
            head->prev=newnode;
            temp=head;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=newnode;
            newnode->next=head;
            newnode->prev=temp;
            tail=newnode;
            }
        traversal(head);
        printf("Do u want ot continue :(1/0) : ");
        scanf("%d",&yes);
    }
    return 0;
}