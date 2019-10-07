#include "stkqq.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int balance(char ch[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	int i;

	//i = 0;
	for(i=0;i<strlen(ch);i++)
	{

		if(ch[i] == '[' || ch[i] == '(' || ch[i] == '{')
		{
			stk = stack_push(stk,ch[i],&res);
			continue;
		}
		else if(ch[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(ch[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(ch[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top==2 || stk->top == -1);
			return 0;//if first symbol is },)or] then it will come out of function.
		}


	}
	//i++;
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);

	return 0;
}

int postfix_stk(char E[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	int j;
	//j = 0;
	for(j=0;j<strlen(E);j++)
    {
        if(isdigit(E[j]))
        {
            stk=stack_push(stk,E[j],&res);
            //printf("houda");
        }
        else
        {
            //printf("is it here");
            char x,y;
            int ch = 0;
            x = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            y = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(E[j]=='+')
            {
                //printf("comoing here");
            ch = x -'0' + y - '0';
            //printf("%d",c);
            }
            else if(E[j]=='-')
            {
                ch = (y-'0') - (x-'0');
            }
            else if(E[j]=='*')
            {
                ch = (y-'0') * (x-'0');
            }
            else if(E[j]=='/')
            {
                ch = (y-'0')/(x-'0');
            }
            //char buffer[2];
            //itoa(c,buffer,10);
            //char pf = c+'0';
           //printf("%c",buffer[1]);

            char pf = ch+'0';
            stk = stack_push(stk,pf,&res);


            //assert(res.data == '11');

        }
        //j++;
    }

//printf("coming here");
stk = stack_peek(stk,&res);
assert(res.data=='6');
//printf(stk->data[stk->top]);

}

int main()
{
	//1.Check balancing of symbols ( like ‘{‘, ‘(‘, ‘[‘ ) and their order using stack.
	char ch[10] = "}((]";
	char c1[20] = "[({})]";
	//printf("ajith");
   	balance(ch);
	balance(c1);

	//2.Evaluate postfix expression using stack.
    	char E[20]="423+1*+3-";

	postfix_stk(E);
	return 0;

}
