/*
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 
*/
#include<stdio.h>
void main()
{
    int n,i,j,a;
    printf("Enter n :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        /*if(i%2==0)
            a=0;
        else
            a=1;
        for(j=1;j<=i;j++)
        {
            printf("%d",a);
            if(a==1)
                a--;
            else
                a++;
        }*/
        for(j=1;j<=i;j++)
            printf("%d ", a ^ j%2==0 )
        printf("\n");
    }
}