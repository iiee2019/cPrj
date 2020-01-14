/*
#pragma once
#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
struct Task
{
	int taskid;
	int priority;
};
struct Heap
{
	int capacity;
	int size;
	struct Task **data;
};
typedef struct Heap* heaptype;

void swap_heap(heaptype heap,int pos1,int ops2);
heaptype create_heap(int capacity);
int empty_heap(heaptype heap);
int full_heap(heaptype heap);
void hold_heap(heaptype heap,int pos);
void insert_heap(heaptype heap,struct Task *newtask);
void decrease_priority(heaptype heap,int where,int priotity);
void increase_priority(heaptype heap, int where, int priotity);

struct Task* delete_min(heaptype heap);

void destroy_heap(heaptype heap);
struct Task* create_task(int taskid, int priotity);

int gettaskbyid(heaptype heap,int id);

#endif // !_PRIORITY_QUEUE_H
*/
