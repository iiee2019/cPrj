/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int capacity;
	int flag;
	int* data;
};
typedef struct Stack* slink;

slink create_stack(int capacity) {
	slink stack = malloc(sizeof(struct Stack));
	if (!stack)
		return stack;
	stack->capacity = capacity;
	stack->flag = -1;
	stack->data = malloc(sizeof(int)*capacity);
	return stack;
}
int isEmpty(slink stack) {
	return stack->flag == -1;
}
int isFull(slink stack) {
	return stack->flag == stack->capacity - 1;
}
void push_stack(slink stack,int item) {
	stack->data[++stack->flag]=item;
}
int pop_stack(slink stack) {
	if (isEmpty(stack))
		return -1;
	return stack->data[stack->flag--];
}
/*
int getCapacity(slink stack) {
	return stack->capacity;
}
void resize(slink stack) {
	int size = 0;
	if(isFull(stack))
		size = getCapacity(stack);
	stack->capacity = size*2;
	printf("%d\t", stack->capacity);
}

int main(){
	slink stack = create_stack(5);
	int data[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0;
	while (!isFull(stack))
		push_stack(stack, data[i++]);
	//resize(stack);
	printf("元素依次为：\t");
	while (!isEmpty(stack))
		printf("%d\t",pop_stack(stack));
	slink stack1 = create_stack(9);
	printf("9个元素依次进栈：\n");
	int j = 0;
	while (i < 9 && !isFull(stack1))
		push_stack(stack1, data[j++]);
	printf("9个元素依次出栈：\n");
	while (!isEmpty(stack1))
		printf("%d\n",pop_stack(stack1));
	system("pause");
	return 0;
}

*/