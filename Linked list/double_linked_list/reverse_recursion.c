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
struct node * reverse(struct node * temp,struct node * head)
{
    if(temp==NULL)
    return head;
    struct node * k;
    k=temp->next;
    temp->next=temp->prev;
    temp->prev=k;
    return reverse(temp->prev,head);
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
    struct node * k;
    printf("\nREVERSED LIST : ");
    head=reverse(head,head); 
    k=head;
    head=tail;                                                            
    tail=k;
    traverse(head); 
    return 0;
}