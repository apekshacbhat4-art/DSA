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
struct node * delete_at_pos(struct node *head,int pos)
{
    struct node *temp=head,*temp1=NULL;
    int i=1;
    while(i<pos)
    {
        temp1=temp;
        temp=temp->next;
        i++;
    }
    temp1->next=temp->next;
    temp->next->prev=temp1;
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
    int yes=1,choice,pos;
    printf("\n\n*** DELETION OF NODE ***\n\n1)At start\n2)At end\n3)At position\n\n");
    while(yes)
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            head=head->next;
            head->prev=0;
            traverse(head);
            break;
            case 2 :
            tail=tail->prev;
            tail->next=0;
            traverse(head);
            break;
            case 3:
            printf("Enter position : ");
            scanf("%d",&pos);
            traverse(delete_at_pos(head,pos));
            break;
        }
        printf("Do you want to continue ? (1/0) : ");
        scanf("%d",&yes);
    }
    return 0;
}