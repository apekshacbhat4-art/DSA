/*
E 
D E 
C D E 
B C D E 
A B C D E 
*/
#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a=0;
        for(j=1;j<=i;j++)
            printf("%c ",65+n-i+a++);
        printf("\n");
    }
}