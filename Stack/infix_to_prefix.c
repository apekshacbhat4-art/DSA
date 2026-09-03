#include<stdio.h>
#include<string.h>
int stack[100];
int top=-1;
char result[100];
int k=0;
char * reverse(char *str)
{
    int i,n=strlen(str),temp;
    for(i=0;i<n/2;i++)
    {
        temp=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
    return str;
}
int isdigitalpha(char c)
{
    if(c>='a'&&c<='z')
    return 1;
    if(c>='A'&&c<='Z')
    return 1;
    if(c>='0'&&c<='9')
    return 1;
    return 0;
}
void push(int val)
{
    stack[++top]=val;
}
void pop()
{
    if(top==-1)
    return;
    if(stack[top]==')')
    {
        top--;
        return;
    }
    result[k++]=stack[top--];
}
void main()
{
    char s[100];
    scanf("%s",s);
    char *str=reverse(s);
    int i=0;
    while(str[i]!='\0')
    {
        if(isdigitalpha(str[i]))
            result[k++]=str[i];
        else 
        {
            if(top!=-1 || stack[top]==')')
            {
                if(str[i]=='(')
                {
                    while(stack[top]!=')')
                    pop();
                    pop();
                }
                else if(str[i]==')')
                push(str[i]);
                else
                {
                    if(str[i]=='^')
                    {
                        if(stack[top]=='^')
                        {
                            while(top!=-1 && stack[top]=='^')
                            pop();
                        }
                    }
                    else if(str[i]=='+' || str[i]=='-')
                    {
                        if(stack[top]!='+' || str[i]!='-')
                        {
                            while(top!=-1 && stack[top]!='+' && stack[top]!='-' && stack[top]!=')')
                            pop();
                        }
                    }
                    else
                    {
                        if(stack[top]=='^')
                        {
                            while(stack[top]=='^')
                            pop();
                        }

                    }
                    push(str[i]);
                }
            }
            i++;
        }
    }
    result[k]='\0';
    printf("%s",reverse(result));
}