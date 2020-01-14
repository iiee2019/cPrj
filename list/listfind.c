/*
#include <stdio.h>
#include "list.h"

llink get_middle_item(llink list) {
	llink first = list;
	llink last = list;
	while (last)
	{
		last = last->next;
		if (last)
			last = last->next;
		first = first->next;
	}
	return first;
}
llink get_kthLat_item(llink list,int k) {
	llink first = list;
	llink last = list;
	int i = 1;
	while (i++<=k&&first)
	{
		last = last->next;
	}
	if (i>k&&!last)
		return first;
	if (!last)
		return NULL;
	while (last)
	{
		first = first->next;
		last = last->next;
	}
	return first;
}
int main(int argc,char const*argv[]) {
	int data[] = {1,2,3,4,5,6,7};
	int size = sizeof(data) / sizeof(int);
	llink list = NULL;
	int i;
	for (i = 0; i < size; i++)
		insert_list(&list, data[i]);
	llink mid = get_middle_item(list);
	printf("middle=%d\n",mid->val);
	llink k;
	for ( i = 1; i <=size; i++)
	{
		k = get_kthLat_item(list, i);
		if(k)
			printf("%d\tlast=%d\n",i,k->val);
	}
	system("pause");
	return 0;
}*/