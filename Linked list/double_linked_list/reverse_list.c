#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *prev;
    struct node *next;
};
void traverse(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }   
}
struct node * reverse(struct node * head,struct node *tail)
{
    struct node * temp=head,*k;
    k=head;
    head=tail;
    tail=k;
    while(temp!=NULL)
    {
        k=temp->next;
        temp->next=temp->prev;
        temp->prev=k;
        temp=temp->prev;
    }
    return head;
}
int main()
{
    struct node *head=NULL,*newnode,*tail,*temp;
    int count=1;
    while(count)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->val);
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
            newnode->prev=NULL;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("Do u want to add(1/0) : ");
        scanf("%d",&count);
    }
    newnode->next=NULL;
    tail=newnode; 
    printf("ORIGINAL LIST : ");
    traverse(head);
    printf("\nREVERSE LIST :  ");
    traverse(reverse(head,tail));

    return 0;
}