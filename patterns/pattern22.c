/*
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
*/
#include<stdio.h>
void main()
{
    int n,i,j,k,a,b=2;
    printf("Enter n :");
    scanf("%d",&n);
    a=n;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d ",n+1-j );
        for(k=1;k<=2*(n-i)-1;k++)
            printf("%d ",n+1-i );
        for(j=1;j<=i;j++)
            printf("%d ", n-i+j);
        printf("\n");
    }
    for(i=1;i<=2*n-1;i++)
    {
        if(a>=1)
            printf("%d ",a--);
        else
            printf("%d ",b++);
    }
    printf("\n");
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
            printf("%d ",n+1-j );
        for(k=1;k<=2*i-1;k++)
            printf("%d ", i+1);
        for(j=1;j<=n-i;j++)
            printf("%d ",i+j );
        printf("\n");
    }
}