#include<stdio.h>
#include<string.h>
void swap(char *s1,char *s2)
{
    char temp[100];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
}
void display(char str[500][500],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%s\n",str[i]);
}
void main()
{
    int n,i,j,k;
    printf("Enter number of students : ");
    scanf("%d",&n);
    char str[n][500];
    printf("Enter names : \n");
    for(i=0;i<n;i++)
    {
        scanf(" %[^\n]",str[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k=0;
            if(str[j][k] == str[j+1][k])
            {
                k=1;
                while(str[j][k]==str[j+1][k])
                    k++;
            }
            if(str[j][k]>str[j+1][k])
                swap(str[j],str[j+1]);
        }
    }
    printf("Sorted names:\n");
    display(str,n);
}