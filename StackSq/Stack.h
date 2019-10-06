#pragma once
#include "../global.h"
#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������
typedef int SElemType;

typedef struct {
	SElemType* base; //��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType* top; //ջ��ָ��
	int stacksize; //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
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