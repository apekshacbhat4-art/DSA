#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * next;
};
void traverse(struct node * head)
{
    int i;
    struct node * temp = head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }
}
struct node * merge(struct node * head1,struct node * head2)
{
    if(head1==0 && head2==0)
    return 0;
    if(head1==0 && head2!=0)
    return head2;
    if(head1!=0 && head2==0)
    return head1;
    struct node *temp1=head1,*temp2=head2;
    if(head2->val<head1->val)
    {
        temp1=head2;
        temp2=head1;
    }
    struct node *head=temp1,*k;
    int i=1;
    while(1)
    {
        if(i==1)
        {
            if(temp1->next==0)
            {
                temp1->next=temp2;
                break;
            }
            else{
                if(temp1->next->val > temp2->val)
                {
                    k=temp1->next;
                    temp1->next=temp2;
                    temp1=k;
                    i=2;
                }
                else
                    temp1=temp1->next;
            }
        }
        else
        {
            if(temp2->next==0)
            {
                temp2->next=temp1;
                break;
            }
            else
            {
                if(temp2->next->val > temp1->val)
                {
                    k=temp2->next;
                    temp2->next=temp1;
                    temp2=k;
                    i=1;
                }
                else
                    temp2=temp2->next;
            }
        }
    }
    return head;
}
int main()
{
    struct node * head1=NULL,*temp1,*newnode1;
    int count=1;
    while (count)
    {
        newnode1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&newnode1->val);
        if (head1 == NULL){
            head1=newnode1;
            temp1=newnode1;
        }
        else {
            temp1->next=newnode1;
            temp1=newnode1;
        }
        printf("Do u want to add another node ?(1/0)");
        scanf("%d",&count);
    }
    newnode1->next=NULL;
    traverse(head1);
    struct node * head=NULL,*temp,*newnode;
    count=1;
    while (count)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&newnode->val);
        if (head == NULL){
            head=newnode;
            temp=newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do u want to add another node ?(1/0)");
        scanf("%d",&count);
    }
    newnode->next=NULL;
    traverse(head);
    printf("\n");
    traverse(merge(head1,head));
    return 0;
}