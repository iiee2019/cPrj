#pragma once
#ifndef BINARYTREE_H  
#define  BINARYTREE_H
#define  STACKSIZE 300

struct BTree
{
	int val;
	struct BTree *left;
	struct BTree *right;
};
typedef struct BTree *btlink;

void insert_btree(btlink*,int);
btlink insert_btree_recursive(btlink,int);
void delete_Btree(btlink*,int);
btlink search_Btree_Recursive(btlink,int);
btlink search_Btree_noRecursive(btlink,int);
void prefix_Recursive(btlink);
void infix_Recursive(btlink);
void suffix_Recursive(btlink);
void prefix_noRecursive(btlink);
void infix_noRecursive(btlink);
void suffix_noRecursive(btlink);
void destroy_tree(btlink);
void bfs(btlink);

#endif