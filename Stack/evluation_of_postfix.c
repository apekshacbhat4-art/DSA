#include<stdio.h>
#include<math.h>
int stack[100];
int top=-1,k=0;
char result[100];
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
    result[k++]=stack[top--];
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
int integer(char c)
{
    return c-48;
}
int pop2()
{
    return stack[top--];
}
int calculation(int op1,int op2,char op)
{
    if(op=='+')
    return op1+op2;
    if(op=='-')
    return op1-op2;
    if(op=='*')
    return op1*op2;
    if(op=='/')
    return op1/op2;
    if(op=='^')
    return pow(op1,op2);
    if(op=='%')
    return op1%op2;
}
char * infix_to_postfix(char *str)
{
    int i=0;
    while(str[i]!='\0')
        {
            if(isdigitalpha(str[i]))
            result[k++]=str[i];
            else
            {
                if(top!=-1 && stack[top]!='(')
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
        result[k]='\0';
        return result;
}
void main()
{
    char str[100];
    printf("Enter expression with numbers : \n");
    scanf("%s",str);
    char * result= infix_to_postfix(str);
    int i=0;
    while(result[i]!='\0')
    {
        if(result[i]>='0'&&result[i]<='9')
        push(integer(result[i]));
        else
        push(calculation(pop2(),pop2(),result[i]));
        i++;
    }
    printf("Final result : %d",pop2());
}
 