/*
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int item;
	struct List* nextLN;
};
struct Queue
{
	int size;
	struct List* head;
	struct List* rear;
};
typedef struct Queue* qlink;
qlink create_queue(void) {
	qlink base = malloc(sizeof(struct Queue));
	if (!base)
		return base;
	base->size = 0;
	base->head = base->rear = NULL;
	return base;
}
int isEmpty(qlink queu) {
	return queu->size == 0;
}
int enQueue(qlink queu,int item) {
	struct List* newLN = malloc(sizeof(struct List));
	if (!newLN)
		return;
	newLN->item = item;
	newLN->nextLN = NULL;
	if (queu->head)
		queu->rear->nextLN = newLN;
	else
		queu->head = newLN;
	queu->rear = newLN;
	queu->size++;
}
int deQueue(qlink queue) {
	if (isEmpty(queue))
		return -1;
	int val = queue->head->item;
	struct List* tmp = queue->head;
	if (queue->head == queue->rear)
		queue->rear = NULL;
	queue->head = queue->head->nextLN;
	free(tmp);
	queue->size--;
	return val;
}

int main() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	qlink queue = create_queue();
	while (i < 5)
		enQueue(queue, data[i++]);
	while (!isEmpty(queue))
		printf("%d\n", deQueue(queue));
	while (i < 10)
		enqueue(queue, data[i++]);
	while (!empty(queue))
		printf("%d\n", dequeue(queue));
	return 0;
}*/