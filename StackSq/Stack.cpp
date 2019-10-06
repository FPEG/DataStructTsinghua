#include "../global.h"
#include "Stack.h"
#include <cstdlib>

Status InitStack(SqStack& S) { //构造一个空栈s
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW); //存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
} // InitStack

Status Push(SqStack& S, SElemType e) { //插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize) {//栈满，追加存储空间
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW); //存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; return OK;//先等于再上移
} //Push

Status Pop(SqStack& S, SElemType& e) { //若栈不空，则删除S的栈顶元素，用e返回其值，并返回 0K;否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = * --S.top; return OK;//先下移再删除
}// Pop

