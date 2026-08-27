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
struct node * reverse(struct node * head,int k)
{
    if(head==0 || head->next==0)
    return head;
    int n=0,i=0,grp;
    struct node *temp1=head;
    while(temp1!=0)
    {
        n++;
        temp1=temp1->next;
    }
    grp=n/k;
    struct node * temp2=head->next,*k1,*p,*q;
    temp1=head;
    while(i!=grp*k)
    {
        i++;
        if(i%k==0)
        {
            if(i/k==1)
            {
                p=head;
                head=temp1;
            }
            else 
            {
                p->next=temp1;
                p=q;
            }
            q=temp2;
            if(temp2!=0)
            {
                temp1=temp2;
                if(temp2->next!=0)
                temp2=temp2->next;
                else
                temp2=0;
            }
            
        }
        else
        {
            if(temp2->next!=0)
            k1=temp2->next;
            else
            k1=0;
            temp2->next=temp1;
            temp1=temp2;
            temp2=k1;
        }
    }
    p->next=q;
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
    printf("Enter k :");
    scanf("%d",&k);
    traverse(reverse(head,k));
    return 0;
}