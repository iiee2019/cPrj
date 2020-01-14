/*

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct List {
	int item;
	struct List* next;
}ListLN;
struct Stack
{
	int size;
	ListLN* head;
};
/ *
struct Stack
{
	int size;
	struct List {
		int item;
		struct List* next;
	}*head;
};* /
typedef struct Stack* slink;
slink create_stack(void) {
	slink stack = malloc(sizeof(struct Stack));
	if (!stack)
		return stack;
	stack->size = 0;
	stack->head = NULL;
	return stack;
}
int isEmpty(slink stack) {
	return stack->size == 0;
}
void push_stack(slink stack,int item) {
	struct List* newLN = malloc(sizeof(struct List));
	if (!newLN)
		return;
	newLN->item = item;
	newLN->next = stack->head;
	stack->head = newLN;
	stack->size++;
}
int pop_stack(slink stack) {
	if (isEmpty(stack))
		return -1;
	struct List* tmp = stack->head;
	int val = stack->head->item;
	stack->head = stack->head->next;
	free(tmp);
	stack->size--;
	return val;
}
int peek_stack(slink stack) {
	if (isEmpty(stack))
		return -1;
	struct List* tmp = stack->head;
	int val = stack->head->item;
	/ *stack->head = stack->head->next;
	free(tmp);
	stack->size--;* /
	return val;
}
int main() {
	slink stack = create_stack();
	int data[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0;
	printf("输入6个元素：");
	while (i < 6)
		push_stack(stack, data[i++]);
	int val=peek_stack(stack);
	printf("栈顶元素：%d\t", val);
	while (!isEmpty(stack))
		printf("%d\t", pop_stack(stack));
	printf("输入9个元素：");
	while (i < 9)
		push_stack(stack, data[i++]);
	while (!isEmpty(stack))
		printf("%d\n", pop_stack(stack));
	system("pause");
	return 0;
}*/