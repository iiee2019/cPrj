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
	//��ӵ�ʱ��ֻ���Ƕ���Ϊ��
	if (obj->head==-1)
	{
		obj->head = 0;
	}
	//����һ������
	obj->rear = (obj->rear + 1) % obj->size;
	obj->data[obj->rear] = e;
}
int deQueue(Queue* obj) {
	//���ӵ�ʱ�򣬴��ⲻ�ؿ��Ƕ���Ϊ�յ�����
	int a = obj->data[obj->head];
	if (obj->head==obj->rear)
	{
		obj->rear = -1;
		obj->head = -1;
		return a;
	}
	//����һ������
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
	//ֻҪ���ҵ�һ������Ϊ�ǿգ��Ҿ����������Ԫ�أ�����������ǿյģ��������һ��������
	if (isEmpty(obj->q1))
		enQueue(obj->q2, x);
	else
		enQueue(obj->q1, x);
}
/ ** Removes the element on top of the stack and returns that element. * /
//ջ������ʱ������ֻ��һ������Ϊ�ǿ�
int myStackPop(MyStack* obj) {
	//q2Ϊ�ǿյ�ʱ��q2����ֱ��q2��ֻ��һ��Ԫ��
	if (isEmpty(obj->q1))
	{
		while (obj->q2->head != obj->q2->rear) {
			//q2���е�Ԫ�أ�����q1
			enQueue(obj->q1, deQueue(obj->q2));
		}
		return deQueue(obj->q2);
	}
	//��֮q1�ǿ�
	while (obj->q1->head!=obj->q1->rear)
	{
		enQueue(obj->q2, deQueue(obj->q1));
	}
	return deQueue(obj->q1);
}
/ ** Get the top element. * /
//ȡջ��Ԫ�أ�����ֻ��һ������Ϊ�ǿգ���ֱ��ȡ�ǿն��е�β������
int myStackTop(MyStack* obj) {
	if (isEmpty(obj->q1)) {
		return obj->q2->data[obj->q2->rear];
	}
	return obj->q1->data[obj->q1->rear];
}
/ ** Returns whether the stack is empty. * /
//���ҽ����������ж��ǿյ�����
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
	printf("ջ�е�Ԫ��Ϊ��");
	int tmp = 0;
	while (!isEmpty(stack1)) {
		tmp = myStackTop(stack1);
		printf("%d\t",tmp);
		myStackPop(stack1);
	}
		
	
	system("pause");
	return 0;
}*/