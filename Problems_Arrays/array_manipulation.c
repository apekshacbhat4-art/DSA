#include<stdio.h>
int find_k(int *a,int s,int n)
{
    if(s%n!=0)
    return -1;
    int k=s/n,found=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    return -1;
    for(i=0;i<n;i++)
    {
        if(a[i]>k)
        a[i]=k;
    }
    return k;
}
void main()
{
    int n,s,i;
    printf("Enter size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter sum : ");
    scanf("%d",&s);
    printf("%d",find_k(a,s,n));
}