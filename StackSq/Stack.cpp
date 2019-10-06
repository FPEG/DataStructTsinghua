#include "../global.h"
#include "Stack.h"
#include <cstdlib>

Status InitStack(SqStack& S) { //����һ����ջs
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW); //�洢����ʧ��
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
} // InitStack

Status Push(SqStack& S, SElemType e) { //����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize) {//ջ����׷�Ӵ洢�ռ�
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW); //�洢����ʧ��
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; return OK;//�ȵ���������
} //Push

Status Pop(SqStack& S, SElemType& e) { //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ�������� 0K;���򷵻�ERROR
	if (S.top == S.base) return ERROR;
	e = * --S.top; return OK;//��������ɾ��
}// Pop

