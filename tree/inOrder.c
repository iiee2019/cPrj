/*

void inTraversal(struct TreeNode* root, int* res, int* returnSize) {
	Stack S;
	S.sp = -1;
	if (!root) {
		*returnSize = 0;
		return 0;
	}
	struct TreeNode* cur = root;
	while (cur || S.sp != -1) {
		while (cur) {
			S.data[++(S.sp)] = cur;
			cur = cur->left;
		}
		if (S.sp != -1) {
			cur = S.data[(S.sp)--];
			res[(*returnSize)++] = cur->val;
			cur = cur->right;
		}
	}
	res[*returnSize] = '\0';
}




















#define MAXLEN 100000

int g_nodeNum = 0;
int g_array[MAXLEN] = { 0 };

void PreTravese(struct TreeNode* root)
{
	if (root == NULL) {
		return;
	}

	PreTravese(root->left);
	g_array[g_nodeNum++] = root->val;
	PreTravese(root->right);
}

int kthSmallest(struct TreeNode* root, int k) {
	g_nodeNum = 0;
	PreTravese(root);
	if (g_nodeNum < k) {
		return 0;
	}
	return g_array[k - 1];
}
*/
