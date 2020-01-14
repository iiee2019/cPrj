#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <malloc.h>

#define  FALSE  0

typedef struct STACK_NODE
{
	STACK_TYPE val;
	struct STACK_NODE *next;
}StackNode;
static StackNode* stack;
void createStack(size_t size) {
}
void destroyStack() {
	while (!isEmpty())
		pop();
}
void push(STACK_TYPE val) {
	StackNode *newNode;
	newNode = malloc(sizeof(StackNode));
	assert(newNode!=NULL);
	newNode->next = stack;
	stack = newNode;
	newNode->val = val;
}
void pop() {
	StackNode* firstNode;
	assert(!isEmpty());
	firstNode = stack;
	stack = firstNode->next;
	free(firstNode);
}
STACK_TYPE top() {
	assert(!isEmpty());
	return stack->val;
}
int isEmpty() {
	return stack == NULL;
}
int isFull() {
	return FALSE;
} 