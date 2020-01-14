/*
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

//nodestack define
static btlink stack[STACKSIZE];
static int sp = -1;
static int isEmpty() {
	return sp == -1;
}
static void push(btlink item) {
	stack[++sp] = item;
}
static btlink pop() {
	return stack[sp--];
}
static btlink top() {
	return stack[sp];
}
//nodestack define OK
//statusstack define 
static int stack2[STACKSIZE];
static int sp2 = -1;
static int isEmpty2(void) {
	return sp2 == -1;
}
static void push2(int status) {
	stack2[++sp2] = status;
}
static btlink pop2() {
	return stack2[sp2--];
}
static btlink top2() {
	return stack2[sp2];
}
static void change2(int newstatus) {
	stack2[sp] = newstatus;
}
//statusstack define OK

void insert_btree(btlink* btree, int val) {
	btlink cur = *btree;
	btlink parent = NULL;
	btlink newLN = malloc(sizeof(struct BTree));
	newLN->val = val;
	newLN->left = newLN->right = NULL;
	if (!cur){
		*btree = newLN;
		return;
	}
	while (cur){
		parent = cur;
		if (cur->val == val)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (parent->val >= val)
		parent->left = newLN;
	else
		parent->right = newLN;
}
btlink insert_btree_recursive(btlink cur, int val) {
	if (!cur){
		btlink newLN = malloc(sizeof(struct BTree));
		newLN->val = val;
		newLN->left = newLN->right = NULL;
		return newLN;
	}
	if (cur->val >= val)
		cur->left = insert_btree_recursive(cur->left, val);
	else
		cur->right = insert_btree_recursive(cur->right, val);
	return cur;
}
btlink find_rightleftmostnode(btlink node) {
	btlink cur = node->right;
	btlink parent = node;
	while (cur->left) {
		parent = cur;
		cur = cur->left;
	}
	if (parent->val >= cur->val)
		parent->left = cur->left;
	else
		parent->right = cur->right;
	return cur;
}
void delete_btree(btlink *btree, int val) {
	btlink cur = *btree;
	btlink parent = NULL;
	btlink target;
	if (!cur)
		return;
	while (cur&&cur->val!=val)
	{
		parent = cur;
		cur = (cur->val > val) ? (cur->left) : (cur->right);
	}
	target = cur;
	if (!target)
		return;
	if (target->left&&target->right) {
		btlink leftmost = find_rightleftmostnode(target);
		target->val = leftmost->val;
		target = leftmost;
	}else if (target->left){
		if (parent){
			if (parent->left == target)
				parent->left = target->left;
			else
				parent->right = target->left;
		}
		else
			*btree = target->left;
	}
	else if (target->right) {
		if (parent){
			if (parent->left == target)
				parent->left = target->right;
			else
				parent->right = target->right;
		}
		else
			*btree = target->right;
	}
	else {
		if (parent){
			if (parent->left == target)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			*btree = NULL;
	}
	free(target);
}
void prefix_Recursive(btlink root) {
	if (root){
		printf("%d", root->val);
		prefix_Recursive(root->left);
		prefix_Recursive(root->right);
	}
}
void infix_recursive(btlink root) {
	if (root) {
		infix_recursive(root->left);
		printf("%d ", root->val);
		infix_recursive(root->right);
	}
}

void suffix_recursive(btlink root) {
	if (root) {
		suffix_recursive(root->left);
		suffix_recursive(root->right);
		printf("%d ", root->val);
	}
}
void prefix_noRecursive(btlink btree) {
	printf("prefix_nonrecursive:\n");
	btlink cur = btree;//p指向当前访问结点
	while (cur||!isEmpty()){
		while (cur) {//若当前结点非空
			printf("%d", cur->val);
			push(cur);//记录该结点到栈，后面回退
			cur = cur->left;
		}
		if (!cur){
			cur = pop();
			cur = cur->right;
		}
	}
	printf("\n");
}
void infix_noRecursive(btlink btree) {
	printf("infix_noRecursive:\n");
	btlink cur = btree;
	while (cur||!isEmpty()){
		while (cur){
			push(cur);
			cur = cur->left;
		}
		if (!cur){
			cur = pop();
			printf("%d",cur->val);
			cur = cur->right;
		}
	}
	printf("\n");
}
void suffix_noRecursive(btlink btree) {
	printf("suffix_nonrecursive:\n");
	btlink cur = btree;
	int status;
	push(cur);
	push2(0);
	while (!isEmpty()){
		status = top2();
		switch (status){
			case 0:
				cur = top();
				change2(1);
				if (cur->left){
					push(cur->left);
					push2(0);
				}
				break;
			case 1:
				cur = top();
				change2(2);
				if (cur->right){
					push(cur->right);
					push2(0);
				}
				break;
			default:
				cur = pop();
				pop2();
				printf("%d",cur->val);
		}
	}
	printf("\n");
}
void destroy_tree(btlink btree) {
	if (btree){
		destroy_tree(btree->left);
		destroy_tree(btree->right);
		free(btree);
	}
}
btlink search_Btree_Recursive(btlink btree, int target) {
	if (!btree||btree->val==target)
		return btree;
	if (btree->val > target)
		return search_Btree_Recursive(btree->left,target);
	else
		return search_Btree_Recursive(btree->right, target);
}
btlink search_Btree_noRecursive(btlink btree, int target) {
	btlink cur = btree;
	btlink retval = NULL;
	while (cur){
		if (cur->val==target){
			retval = cur;
			break;
		}
		else
			cur = cur->val > target ? cur->left : cur->right;
	}
	return retval;
}
*/
