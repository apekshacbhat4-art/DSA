/*
1             1 
1 2         2 1 
1 2 3     3 2 1 
1 2 3 4 4 3 2 1 
*/
#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d ",j);
        for(k=1;k<=2*(n-i);k++)
            printf("  ");
        for (j=1;j<=i;j++)
            printf("%d ",i-j+1);
        printf("\n");
    }
}