#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <malloc.h>

/*
用动态分配数组实现堆栈
堆栈的长度在创建堆栈的函数被调用的时候给出，该函数必须在任何其他操作堆栈的函数被调用之前调用

*/
static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

void createStack(size_t size) {
	assert(stack_size==0);
	stack_size = size;
	stack = malloc(stack_size * sizeof(STACK_TYPE));
	assert(stack != NULL);
}
void destroyStack(void) {
	assert(stack_size>0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}
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
	assert(stack_size>0);
	return top_element == -1;
}

int isFull() {
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}