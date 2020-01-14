#include <stdio.h>
#include "binarytree.h"
#include "copybinarytree.h"
//nodestack define
static btlink stack[STACKSIZE];
static int sp = -1;
static int empty() {
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

btlink copy_btree_norecursive(btlink btree) {
	if (!btree)
		return NULL;
	btlink root = malloc(sizeof(struct BTree));
	if (!root)
		exit(1);
	root->val = btree->val;
	root->left = copy_btree_norecursive(btree->left);
	root->right = copy_btree_norecursive(btree->right);
	return root;
}
btlink copy_btree_norecursive(btlink btree) {
	btlink cur = btree;
	btlink newbtree, newnode, parent=NULL;
	while (cur||!empty()){
		while (cur){
			newnode = malloc(sizeof(struct BTree));
			newnode->val = cur->val;
			newnode->left = newnode->right = NULL;
			push(parent);
			push(newnode);
			push(cur);
			parent = newnode;
			cur = cur->left;
		}
		if (!cur){
			cur = pop();
			newnode = pop();
			parent = pop();
			if (parent){
				if (parent->val >= newnode->val)
					parent->left = newnode;
				else
					parent->right = newnode;
			}
			else {
				newbtree = newnode;
			}
			parent = newnode;
			cur = cur->right;
		}
	}
	return newbtree;
}