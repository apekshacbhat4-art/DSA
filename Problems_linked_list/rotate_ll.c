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
struct node * rotate(struct node * head,int k)
{
    if(head==0 || head->next==0)
    return head;
    int n=0,i=0;
    struct node * temp1=head,*temp2,*temp3;
    while(temp1!=0)
    {
        n++;
        temp1=temp1->next;
    }
    temp1=head;
    if(k%n==0)
    return head;
    if(k>n)
    k=k%n;
    while(temp1->next!=0)
    {
        i++;
        if(i==n-k)
        {
            temp2=temp1;
            temp3=temp1->next;
        }
        temp1=temp1->next;
    }
    temp1->next=head;
    temp2->next=0;
    head=temp3;
    return head;
}
int main()
{
    struct node * head=NULL,*temp,*newnode;
    int count=1;
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
    int k;
    printf("Enter k : ");
    scanf("%d",&k);
    traverse(rotate(head,k));
    return 0;
}