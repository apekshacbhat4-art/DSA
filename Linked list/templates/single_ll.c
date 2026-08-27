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
    return 0;
}