#include<stdio.h>
char stack[100];
int top=-1;
void push(int val)
{
    stack[++top]=val;
}
void pop()
{
    if(top==-1)
    return;
    if(stack[top]=='(')
    {
        top--;
        return;
    }
    printf("%c",stack[top--]);
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
void main()
{
    char str[100];
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0')
    {
        if(isdigitalpha(str[i]))
        printf("%c",str[i]);
        else
        {
            if(top!=-1 && stack[top]!='(' || str[i]==')')
            {
                if(str[i]==')')
                {
                    while(stack[top]!='(')
                    pop();
                    pop();
                }
                else
                {
                if(str[i]=='+'||str[i]=='-')
                {
                    while(top!=-1 && stack[top]!='(')
                        pop();
                }
                else if(str[i]=='*' || str[i]=='/' || str[i]=='%')
                {
                    while(top!=-1 && stack[top]!='+' && stack[top]!='-' &&stack[top]!='(')
                    pop();
                }
                push(str[i]);
                }
            }
            else
            push(str[i]);
        }
    
        i++;
    }
    while(top!=-1)
    pop();
}
