/*
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

llink find_item(llink list,int target) {
	while (list)
	{
		if (list->val==target)
			return list;
		list = list->next;
	}
	return NULL;
}
void delete_item_advanced(llink node) {
	llink nextNode = node->next;
	if (nextNode)
	{
		node->val = nextNode->val;
		node->next = nextNode->next;
		free(nextNode);
	}
	else {
		printf("cannot delete %d for its the last item\n",node->val);
	}
}

int main(int argc, char const *argv[]) {
	int data[] = {1,2,3,4,5,6,7};
	int size = sizeof(data) / sizeof(int);
	llink list = NULL;
	printf("���β��뵽����");
	for (int i=0;i<size;i++)
	{
		insert_list(&list, data[i]); 
	}
	printf("���������");
	display_list(list);
	int test = 2;
	//Ѱ�Ҵ�������ֵΪ2�Ľڵ�
	llink node= find_item(list, test);
	//ɾ���˽ڵ�
	delete_item_advanced(node);
	printf("ɾ���˽ڵ�������");
	display_list(list);
	int test1 = 3;
	//Ѱ�Ҵ�������ֵΪ2�Ľڵ�
	llink node1 = find_item(list, test1);
	//ɾ���˽ڵ�
	delete_item_advanced(node1);
	printf("ɾ���˽ڵ�������");
	display_list(list);
	system("pause");
	return 0;
}*/