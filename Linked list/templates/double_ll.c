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
    traverse(head);
    return 0;
}