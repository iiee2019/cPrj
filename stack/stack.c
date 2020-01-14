/*
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100
/ ************************************************************************ /
/ * 
	��һ����̬����ʵ�ֶ�ջ������ĳ���ͨ��#define����
	����ģ�����½��б�����ʵ��
* /
/ ************************************************************************ /

static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

void push(STACK_TYPE val) {
	assert(!isFull());
	top_element += 1;
	stack[top_element] = val;
}
void pop() {
	assert(!isEmpty());
	top_element -= 1;
}

STACK_TYPE top() {
	assert(!isEmpty());
	return stack[top_element];
}
int isEmpty() {
	return top_element == -1;
}
int isFull() {
	return top_element == STACK_SIZE - 1;
}

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0;i<10;i++) {
		push(arr[i]);
	}
	printf("%d\n", isEmpty());
	printf("%d\n", isFull());
	printf("����ջ֮ǰ��");
	printf("%d\n", top());
	pop();
	printf("����ջ֮��");
	printf("%d\n", top());

	system("pause");
	return 0;
}*/