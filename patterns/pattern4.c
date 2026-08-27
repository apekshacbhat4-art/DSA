/*
1
22
333
4444
55555
*/
#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d",i);
        printf("\n");
    }
}