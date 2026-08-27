/*
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
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
            printf("*");
        for(k=1;k<=2*(n-i);k++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
            printf("*");
        for(k=1;k<=2*i;k++)
            printf(" ");
        for(j=1;j<=n-i;j++)
            printf("*");
        printf("\n");
    }
}