#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;
char result[100];
int k=0;
void display()
{
    printf("\nSTACK  :  ");
    for(int i=0;i<=top;i++)
    printf("%c\t",stack[i]);
}
char * reverse(char *str)
{
    int temp;
    char * p=str;
    char *q=&p[strlen(p)-1];
    while(*p!=*q)
    {
        temp=*p;
        *p++=*q;
        *q--=temp;
    }
    return str;
}
int isalphadigit(char c)
{
    if(c>='a'&&c<='z')
    return 1;
    if(c>='A'&&c<='Z')
    return 1;
    if(c>='0'&&c<='9')
    return 1;
    return 0;
}
void push(char c)
{
    stack[++top]=c;
}
void pop()
{
    if(top==-1)
    return;
    if(stack[top]==')')
    top--;
    else
    result[k++]=stack[top--];
}
void main()
{
    char str[100];
    scanf("%s",str);
    char * s = reverse(str);
    while(*s!='\0')
    {
        if(isalphadigit(*s))
        result[k++]=*s;
        else
        {
            if(top!=-1 && stack[top]!=')')
            {
                if(*s=='(')
                {
                    while(stack[top]!=')')
                    pop();
                    pop();
                }
                else if(*s==')')
                push(*s);
                else 
                {
                    if(*s=='^'|| *s=='*' ||*s=='/'||*s=='%')
                    {
                        if(stack[top]=='^')
                        {
                            while(top!=-1 && stack[top]=='^')
                            pop();
                        }
                    }
                    else
                    {
                        if(stack[top]!='+' && stack[top]!='-')
                        {
                            while(top!=-1 && stack[top]!='+' && stack[top]!='-' && stack[top]!=')')
                            pop();
                        }
                    }
                    push(*s);
                }
            }
            else
            push(*s);
        }
        display();
        printf("\nRESULT :  %s\n",result); 
        s++;
    }
    while(top!=-1)
    pop();
    result[k]='\0';
    char * prefix=reverse(result);
    printf("%s",prefix);
}