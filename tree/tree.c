/*
#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define  TREE_SIZE 100	   / * Max # of values in the tree * /
#define  ARRAY_SIZE  (TREE_SIZE+1)

static TREE_TYPE  tree[ARRAY_SIZE];

static int left_child(int current) {
	return current * 2;
}
static int right_child(int current) {
	return current * 2+1;
}
void insert(TREE_TYPE val) {
	int current;
	assert(val!=0);
	current = 1;
	while (tree[current]!=0)
	{
		if (val < tree[current])
			current = left_child(current);
		else {
			assert(val!=tree[current]);
			current = right_child(current);
		}
		assert(current<ARRAY_SIZE);
	}
	tree[current] = val;
}
TREE_TYPE* find(TREE_TYPE val) {
	int current=1;
	while (current<ARRAY_SIZE&&tree[current]!=val)
	{
		if (val < tree[current])
			current = left_child(current);
		else
			current = right_child(current);
	}
	if (current < ARRAY_SIZE)
		return tree + current;
	else
		return 0;
}
static void do_pre_order_traverse(int current,
	void(*callback)(TREE_TYPE val)) {
	if (current < ARRAY_SIZE&&tree[current] != 0) {
		callback(tree[current]);
		do_pre_order_traverse(left_child(current), callback);
		do_pre_order_traverse(right_child(current), callback);
	}
}

void pre_Order_Traverse(void(*callback)(TREE_TYPE val)) {
	do_pre_Order_Traverse(1, callback);
}*/