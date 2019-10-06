#pragma once
#include "../global.h"
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
typedef int SElemType;

typedef struct {
	SElemType* base; //在栈构造之前和销毁之后，base的值为NULL
	SElemType* top; //栈顶指针
	int stacksize; //当前已分配的存储空间，以元素为单位
}SqStack;

	
Status InitStack(SqStack& S);
Status DestroyStack(SqStack& S);
Status ClearStack(SqStack& S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType& e);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
Status StackTraverse(SqStack S, Status(*visit)());