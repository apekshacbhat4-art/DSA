/*
A
AB
ABC
ABCD
ABCDE
*/
#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
            printf("%c",65+j);
        printf("\n");
    }
}