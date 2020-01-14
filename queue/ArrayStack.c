/*
#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 100
#define  true 1
#define  false 0
struct Stack
{
	int Data[MAXSIZE];
	int top;
};
typedef struct Stack MyStack;
typedef struct 
{
	MyStack s1;
	MyStack s2;
}MyQueue;
MyQueue* myQueueCreate() {                          / *初始化你这里的数据结构* /
	MyQueue* tmpQueue = (MyQueue*)malloc(sizeof(MyQueue));
	tmpQueue->s1.top = -1;
	tmpQueue->s2.top = -1;
	return tmpQueue;
}
void mtQueuePush(MyQueue* obj,int x) {
	if (obj->s1.top<MAXSIZE)		//判断栈是否满了
	{
		while (obj->s1.top!=-1)
		{
			obj->s2.Data[++(obj->s2.top)] = obj->s1.Data[(obj->s1.top)--];
		}
		obj->s1.Data[++(obj->s1.top)] = x; //把push的元素压入s1栈（此时S1栈为空，它的元素都已经全部给了s2） 
		while (obj->s2.top!=-1)
		{
			obj->s1.Data[++(obj->s1.top)] = obj->s2.Data[(obj->s2.top)--];   //再把s2栈中的元素全部反转压入s1
		}
	}
}
int myQueuePop(MyQueue* obj) {
	if (obj->s1.top != -1)
		return obj->s1.Data[(obj->s1.top)--];
	return NULL;
}
int myQueuePeek(MyQueue* obj) {
	if (obj->s1.top != -1)
		return obj->s1.Data[obj->s1.top];
	return NULL;
}
int myQueuEmpty(MyQueue* obj) {
	if (obj->s1.top == -1)
		return true;
	return false;
}
void myQueueFree(MyQueue *obj) {
	free(obj);
}*/