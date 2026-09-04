#include<stdio.h>
#include<string.h>
#include<math.h>
char stack[100];
int stack1[100];
int top1=-1;
int top=-1;
char result[100];
int k=0;
int char_to_int(char c)
{
    return c-48;
}
int calc(int op2,int op1,char op)
{
    if(op=='+')
    return op1+op2;
    if(op=='-')
    return op1-op2;
    if(op=='*')
    return op1*op2;
    if(op=='/')
    return op1/op2;
    if(op=='%')
    return op1%op2;
    if(op=='^')
    return pow(op1,op2);
}
char * reverse(char *str)
{
    int temp;
    char * p=str;
    char *q=&str[strlen(str)-1];
    while(p<=q)
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
void push1(int val)
{
    stack1[++top1]=val;
}
int pop2()
{
    return stack1[top1--];
}
char * infix_to_prefix(char *s)
{
    while(*s!='\0')
    {
        if(isalphadigit(*s))
        result[k++]=*s;
        else
        {
            if(top!=-1 && stack[top]!=')' || *s=='(')
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
        s++;
    }
    while(top!=-1)
    pop();
    result[k]='\0';
    return result;
}   
void main()
{
    char str[100];
    printf("Enter expression with numbers : \n");
    scanf("%s",str);
    char * result = infix_to_prefix(reverse(str));
    while(*result!='\0')
    {
        if(*result>='0'&&*result<='9')
        push1(char_to_int(*result));
        else
        push1(calc(pop2(),pop2(),*result));
        result++;
    }
    printf("Final result : %d",pop2());
}