/*
      A 
    A B A 
  A B C B A 
A B C D C B A 
*/

#include<stdio.h>
void main()
{
    int n,i,j,a,k;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a=0;
        for(k=1;k<=n-i;k++)
            printf("  ");
        for(j=1;j<=2*i-1;j++)
        {
            if(j<=i)
                a++;
            else
                a--;
            printf("%c ",64+a);

        }
        printf("\n");
    }

}