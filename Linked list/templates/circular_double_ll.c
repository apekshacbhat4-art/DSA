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
    printf("Forward List:\t");
    do{
        printf("%d\t",temp->val);
        temp=temp->next;
    }while(temp!=head);
}
void traversal_back(struct node * tail)
{
    struct node * temp=tail;
    printf("\nBackward List:\t");
    do{
        printf("%d\t",temp->val);
        temp=temp->prev;
    }while(temp!=tail);
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
    traversal_back(tail);
    return 0;
}