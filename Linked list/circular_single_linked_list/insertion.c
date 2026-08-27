#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * next;
};
void traversal(struct node * head)
{
    struct node * temp=head;
    do{
        printf("%d\t",temp->val);
        temp=temp->next;
    }while(temp!=head);
}
int main()
{
    struct node * head=NULL,*newnode,*temp;
    int count=1;
    while(count)
    {
        newnode=(struct node * )malloc(sizeof(struct node ));
        printf("Enter data : ");
        scanf("%d",&newnode->val);
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do u want to add(1/0) : ");
        scanf("%d",&count);
    }
    newnode->next=head; 
    traversal(head);
    printf("\n*INSERTION OF NODE\n\n1)At start\n2)At end\n");
    int yes=1;
    while(yes)
    {
        newnode=(struct node * )malloc(sizeof(struct node));
        printf("Enter new data :");
        scanf("%d",&newnode->val);
        printf("Enter choice : ");
        scanf("%d",&count);
        if (count == 1)
        {
            newnode->next=head->next;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
        traversal(head);
        printf("Do u want ot continue :(1/0) : ");
        scanf("%d",&yes);
    }
    return 0;
}