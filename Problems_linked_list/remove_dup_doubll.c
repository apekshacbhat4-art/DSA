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
struct node * remove_dup(struct node* head)
{
    if(head==0 || head->next==0)
    return head;
    struct node * temp1=head,*temp=head->next;
    while(temp!=0)
    {
        if(temp1->val==temp->val)
        {
            if(temp->next!=0)
            {
                temp1->next=temp->next;
                temp1->next->prev=temp1;
                temp=temp->next;
            }
            else
            {
                temp1->next=0;
                temp=0;
            }
        }
        else
        {
            temp1=temp;
            temp=temp->next;
        }
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
    traverse(head);
    printf("\n");
    traverse(remove_dup(head));
    return 0;
}