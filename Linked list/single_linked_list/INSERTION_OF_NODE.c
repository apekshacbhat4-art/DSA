#include<stdio.h>
#include<stdlib.h>
struct node {
    int x;
    struct node * p;
};
void traverse(struct node * head)
{
    int i;
    struct node * temp = head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->x);
        temp=temp->p;
    }
}

int main()
{
    struct node * head=NULL,*temp,*newnode,*temp1=NULL;
    int count=1,key,i=1,yes=1   ;
    while (count)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&newnode->x);
        if (head == NULL){
            head=newnode;
            temp=newnode;
        }
        else {
            temp->p=newnode;
            temp=newnode;
        }
        printf("Do u want to add another node ?(1/0)");
        scanf("%d",&count);
    }
    newnode->p=NULL;
    traverse(head);
    printf("\n\n\n***INSERTION OF DATA***\n\n");
    printf("1)Insert at beginning\n2)Insert at end\n3)Insert before a data\n4)Insert after a data\n5)Insert at position\n\n\n");
    while(yes)
    {
    printf("Enter choice  :");
    scanf("%d",&count);
    newnode=(struct node * )malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode->x);
    switch (count)
    {
        case 1:
        newnode->p=head;
        head=newnode;
        traverse(head);
        break;
        case 2:
        temp=head;
        while(temp!=NULL)
        {
            temp1=temp;
            temp=temp->p;
        }
        newnode->p=NULL;
        temp1->p=newnode;
        traverse(head);
        break;
        case 3:
        printf("Enter the data before which new data to be added :");
        scanf("%d",&key);
        temp=head;
        while(temp!=NULL)
        {
            if (temp->x==key)
            break;
            temp1=temp;
            temp=temp->p;
        }
        newnode->p=temp;
        temp1->p=newnode;
        traverse(head);
        break;
        case 4:
        printf("Enter the data after which new data to be added ");
        scanf("%d",&key);
        temp=head;
        while(temp!=NULL)
        {
            if (temp->x == key)
            {
                temp1=temp;
                temp=temp->p;
                break;
            }
            temp1=temp;
            temp=temp->p;
        }
        temp1->p=newnode;
        newnode->p=temp;
        traverse(head);
        break;
        case 5:
        printf("Enter position: ");
        scanf("%d",&key);
        temp=head;
        while(i<key)
        {
            temp1=temp;
            temp=temp->p;
            i++;
        }
        temp1->p=newnode;
        newnode->p=temp;
        traverse(head);
        break;
        printf("Do you want to continue?(1/0): ");
        scanf("%d",&yes);
    }
}
    return 0;
}