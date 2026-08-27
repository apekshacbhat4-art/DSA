#include<stdio.h>
struct node {
    int val;
    struct node * next;
};
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
    return 0;
}