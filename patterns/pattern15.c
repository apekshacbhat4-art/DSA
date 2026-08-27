/*
ABCDE
ABCD
ABC
AB
A
*/
#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n+1-i;j++)
            printf("%c",65+j);
        printf("\n");
    }
}