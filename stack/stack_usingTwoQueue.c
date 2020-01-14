/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  LEN 20
#define  false 0
#define  true 1
#define  bool int


typedef struct queue
{
	int* data;
	int head;
	int rear;
	int size;
}Queue;
typedef struct 
{
	Queue *q1;
	Queue *q2;
}MyStack;

Queue *initQueue(int k) {
	Queue *base = (Queue*)malloc(sizeof(Queue));
	base->data = (int *)malloc(k * sizeof(int));
	base->head = -1;
	base->rear = -1;
	base->size = k;
	return base;
}
void enQueue(Queue *obj,int e) {
	//入队的时候只考虑队列为空
	if (obj->head==-1)
	{
		obj->head = 0;
	}
	//队列一般情形
	obj->rear = (obj->rear + 1) % obj->size;
	obj->data[obj->rear] = e;
}
int deQueue(Queue* obj) {
	//出队的时候，此题不必考虑队列为空的情形
	int a = obj->data[obj->head];
	if (obj->head==obj->rear)
	{
		obj->rear = -1;
		obj->head = -1;
		return a;
	}
	//队列一般情形
	obj->head = (obj->head + 1) % obj->size;
	return a;
}
int isEmpty(Queue* obj) {
	return obj->head == -1;
}


/ ** Initialize your data structure here. * /
MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	obj->q1 = initQueue(LEN);
	obj->q2 = initQueue(LEN);
	return obj;
}
/ ** Push element x onto stack. * /
void myStackPush(MyStack* obj, int x) {
	//只要我找到一个队列为非空，我就向里面添加元素，如果两个都是空的，那随便哪一个都可以
	if (isEmpty(obj->q1))
		enQueue(obj->q2, x);
	else
		enQueue(obj->q1, x);
}
/ ** Removes the element on top of the stack and returns that element. * /
//栈弹出的时候，有且只有一个队列为非空
int myStackPop(MyStack* obj) {
	//q2为非空的时候，q2出列直到q2中只有一个元素
	if (isEmpty(obj->q1))
	{
		while (obj->q2->head != obj->q2->rear) {
			//q2出列的元素，入列q1
			enQueue(obj->q1, deQueue(obj->q2));
		}
		return deQueue(obj->q2);
	}
	//反之q1非空
	while (obj->q1->head!=obj->q1->rear)
	{
		enQueue(obj->q2, deQueue(obj->q1));
	}
	return deQueue(obj->q1);
}
/ ** Get the top element. * /
//取栈顶元素，有且只有一个队列为非空，我直接取非空队列的尾部即可
int myStackTop(MyStack* obj) {
	if (isEmpty(obj->q1)) {
		return obj->q2->data[obj->q2->rear];
	}
	return obj->q1->data[obj->q1->rear];
}
/ ** Returns whether the stack is empty. * /
//当且仅当两个队列都是空的情形
bool myStackEmpty(MyStack* obj) {
	if (obj->q1->head == -1 && obj->q2->head == -1)
		return true;
	return false;
}
void myStackFree(MyStack* obj) {
	free(obj->q1->data);
	obj->q1->data = NULL;
	free(obj->q1);
	obj->q1 = NULL;
	free(obj->q2->data);
	obj->q2->data = NULL;
	free(obj->q2);
	obj->q2 = NULL;
	free(obj);
	obj = NULL;
}

int main() {
	MyStack* stack1 = myStackCreate();
	int data[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0;
	for (i = 0; i < 9; i++) {
		myStackPush(stack1, data[i]);
	}
	printf("栈中的元素为：");
	int tmp = 0;
	while (!isEmpty(stack1)) {
		tmp = myStackTop(stack1);
		printf("%d\t",tmp);
		myStackPop(stack1);
	}
		
	
	system("pause");
	return 0;
}*/