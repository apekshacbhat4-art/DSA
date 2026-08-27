#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * next;
    struct node * prev;
};
void traverse(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }   
}
struct node * remove_target(struct node *  head,int k)
{
    if(head==0)
    return head;
    if( head->next==0)
    {
        if(head->val==k)
        return 0;
        return head;
    }
    struct node * temp=head,*temp1=0;
    while(temp!=0)
    {
        if(temp->val==k)
        {
            if(temp1!=0)
            {
                if(temp->next!=0)
                {
                    temp1->next=temp->next;
                    temp1->next->prev=temp1;
                }
                else
                {
                    temp1->next=0;
                }
                temp=temp->next;
            }
            else
            {
                head=temp->next;
                head->prev=0;
                temp1=head;
                temp=temp->next;
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
    int k;
    printf("Enter target :");
    scanf("%d",&k);
    traverse(remove_target(head,k));
    return 0;
}