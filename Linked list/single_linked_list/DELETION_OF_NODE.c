#include<stdlib.h>
struct node{
    int x;
    struct node * p;
};
void traverse(struct node * head)
{
    struct node * temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->x);
        temp=temp->p;
    }
}
int main()    
{
    struct node * head=NULL,*newnode,*temp,*temp1,*temp2;
    int count,pos,i=1,yes=1;
    while(count)
    {
        newnode=(struct node * )malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->x);
        if (head==NULL)
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
    printf("\n\n\n**DELETION OF NODE**\n\n\n");
    printf("1)At beginning\n2)At end\n3)At position\n\n");
    while(yes)
    {
    printf("Enter choice : ");
    scanf("%d",&count);
    switch (count)
    {
        case 1: 
        head=head->p;
        traverse(head);
        break;
        case 2:
        temp=head;
        while(temp!=NULL)
        {
            if(((temp->p)->p)==NULL)
            break;
            temp=temp->p;
        }
        temp->p=NULL;
        traverse(head);
        break;
        case 3:
        printf("Enter position : ");
        scanf("%d",&pos);
        if (pos==1)
        head=head->p;
        else
    {
        temp=head;
        temp2=head->p;
        while (i<=pos-1)
        {
            temp1=temp;
            temp2=temp2->p;
            temp=temp->p;
            i++;
        }
        temp1->p=temp2;
    }
        traverse(head);
        break;
    }
    printf("Do u want to continue(1/0):");
    scanf("%d",&yes);
}
    return 0;
}