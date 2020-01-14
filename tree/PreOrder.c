/*
#include <stdio.h>

#define MAXLEN 100000

int data[MAXLEN] = { 0 };
int index = 0;
void inOrderTree(struct TreeNode* root);
int kthSmallest(struct TreeNode* root, int k) {
	inOrderTree(root);
	if()
	return data[k - 1];
}
void inOrderTree(struct TreeNode* root) {
	if (root == NULL)
		return;
	inOrderTree(root->left);
	data[index++] = root->val;
	inOrderTree(root->right);
}*/