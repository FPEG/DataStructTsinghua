#include <cstdio>
#include "../StackSq/Stack.h"
//test update
void conversion()
{
	SqStack S;
	InitStack(S);
	int N;
	scanf("%d", &N);
	while (N)
	{
		Push(S, N%8);
		N = N / 8;
	}
	while (StackEmpty(S))
	{
		SElemType e;
		Pop(S,e);
		printf("%d", e);
	}
	//StackTraverse();
	
}


Status matching(SqStack S,char * exp)
{//(({(())}))
	int e;
	int i=0;
	while(exp[i]!='\0')
	{
		if(exp[i]=='(')
		{
			Push(S, 1);
		}
		if(exp[i]==')')
		{
			GetTop(S, e);
			if(e!=1)
			{
				return ERROR;
			}
			Pop(S,e);
		}
		i++;
	}
	if(StackEmpty(S))
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}