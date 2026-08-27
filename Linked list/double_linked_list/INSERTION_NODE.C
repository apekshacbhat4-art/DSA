#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *prev;
    struct node *next;
};
struct node * create()
{
    struct node *newnode=(struct node * )malloc(sizeof(struct node));
    printf("\nEnter new data : ");
    scanf("%d",&newnode->val);
    return newnode;
}
void traverse_forward(struct node* temp)
{
    printf("Forward List-\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }   
}
void traverse_backward(struct node * temp)
{
    printf("\nBackward List-\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->prev;
    }
}
struct node *  insertAtBeg(struct node * head,struct node * newnode)
{
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    return newnode;
}
void insertAtEnd(struct node * tail,struct node * newnode)
{
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
    tail= newnode;
}
struct node * insertAtpos(int pos,struct node* head,struct node * newnode)
{
    if(pos==1)
    return insertAtBeg(head,newnode);
    struct node * temp=head;
    int i=1;
    /*for(i=1;i<pos;i++)
    {
        if(temp==NULL)
            temp=head;
        else
            temp=temp->next;
    }*/
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=newnode;
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
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
    traverse_forward(head);
    traverse_backward(tail);
    head=insertAtBeg(head,create());
    printf("\nAt beginning : ");
    traverse_forward(head);
    insertAtEnd(tail,create());
    printf("\nAt end : ");
    traverse_forward(head);
    int pos;
    printf("\nEnter pos :");
    scanf("%d",&pos);
    printf("\nAt pos: ");
    head=insertAtpos(pos,head,create());
    traverse_forward(head);
    printf("\nEnter pos after which data to be added :");
    scanf("%d",&pos);
    traverse_forward(insertAtpos(pos+1,head,create()));
    return 0;
}