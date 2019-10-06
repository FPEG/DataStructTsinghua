// StackSq.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	void* vptr;
	vptr = new int;
	*(int *)vptr = 65;
	std::cout << *(double*)vptr << std::endl;
}

