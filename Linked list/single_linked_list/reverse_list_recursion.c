#include<stdio.h>
#include<stdlib.h>
struct node {
    int x;
    struct node * p;
};
void traverse(struct node * head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->x);
        temp=temp->p;
    }
}
struct node * reverse(struct node * head,struct node*temp1,struct node *temp2,struct node * k)
{
    if(temp2==NULL)
    {
        head->p=NULL;
        head=temp1;
        return head;
    }
    k=temp2->p;
    temp2->p=temp1;
    return reverse(head,temp2,k,NULL);
}
int main()
{
    struct node * head=NULL,*newnode,*temp;
    int count=1;
    while(count)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->x);
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->p=newnode;
            temp=newnode;
        }
        printf("Do u want to add(1/0): ");
        scanf("%d",&count);
    }
    newnode->p=NULL;
    traverse(head);
    printf("\nREVERSED LIST-\t");
    head=reverse(head,head,head->p,NULL);
    traverse(head);
    return 0;
}