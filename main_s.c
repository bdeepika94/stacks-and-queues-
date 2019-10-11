#include "stj.h"
#include "q.h"
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
void constant()
{
Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

q=queue_add(q,10,&Qres);
q=queue_add(q,20,&Qres);
q=queue_add(q,30,&Qres);
q=queue_add(q,40,&Qres);

assert(q->count==4);
int d2count=1;
int d3count=q->count;

while(d2count<=d3count)
{
int dcount=1;
while(dcount<q->count)
{
	q = queue_delete(q,&Qres);
	q = queue_add(q,Qres.data,&Qres);
	dcount++;
}
	q = queue_delete(q,&Qres);

d2count++;
}
assert(Qres.data==10);
}

void stack_toqueue()
{
	Stack stk = stack_new(10);
Stack *s=&stk;
Stack_Result Sres;

Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

s = stack_push(s,93,&Sres);
s = stack_push(s,53,&Sres);
s = stack_push(s,73,&Sres);
s = stack_push(s,83,&Sres);

int element = 53;
int count = 0;
int i=0;
while(i<=s->top+1)
{
s = stack_peek(s,&Sres);
if(Sres.data==element)
{
	break;
}
else
{
	s = stack_pop(s,&Sres);
	q = queue_add(q,Sres.data,&Qres);
	count++;
}
i++;
}

int dcount=count;
int d1count=count;
while(count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	count--;
}
s = stack_peek(s,&Sres);
assert(Sres.data==73);

while(dcount!=0)
{
	s=stack_pop(s,&Sres);
	q=queue_add(q,Sres.data,&Qres);
	dcount--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==53);


while(d1count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	d1count--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==83);

}

/*Stack* addQueue(Stack *s1,int32_t element,Stack_Result Sres1)
{

	s1=stack_push(s1,element,&Sres1);
	return s1;
}
*/
Stack* deleteQueue(Stack *s1,Stack *s2,Stack_Result Sres1,Stack_Result Sres2)
{
	while(s1->top>-1)
	{
	s1 = stack_pop(s1,&Sres1);
	int32_t popelement = Sres1.data;
	s2 = stack_push(s2,popelement,&Sres2);
	}
	s2 = stack_pop(s2,&Sres2);
	return s2;
}


void queueUsingStacks()
{
	Stack stk1 = stack_new(10);
	Stack *s1=&stk1;
	Stack_Result Sres1;

	s1 = stack_push(s1,10,&Sres1); //it takes only one time to push the values
	s1 = stack_push(s1,20,&Sres1);
	s1 = stack_push(s1,50,&Sres1);

	Stack stk2 = stack_new(10);
	Stack *s2=&stk2;
	Stack_Result Sres2;


	s2 = deleteQueue(s1,s2,Sres1,Sres2);
	s1 = stack_peek(s1,&Sres1);
	assert(s1->top==-1);

	s2 = stack_peek(s2,&Sres2);
	assert(Sres2.data==20);
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
	constant();
       stack_toqueue();
	queueUsingStacks();
	return 0;

}
