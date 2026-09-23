#include<stdio.h>
void prefixSum(int *a,int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        a[i]=sum;
    }
}
void main()
{
    int n,i;
    printf("Enter size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    prefixSum(a,n);
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}