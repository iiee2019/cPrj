/*
#include <stdio.h>
#include  "list.h"

void reverse_non_recursive(llink* list) {
	llink prevLN = NULL;
	llink cur = *list;
	llink nextLN=NULL;
	while (cur)
	{
		nextLN = cur->next;
		cur->next = prevLN;
		prevLN = cur;
		cur = nextLN;
	}
	*list = prevLN;
}
llink reverse_recursive(llink *list,llink cur) {
	if (!cur)
		return NULL;
	llink prevLN = reverse_recursive(list, cur->next);
	cur->next = NULL;
	if (prevLN)
		prevLN->next = cur;
	else
		*list = cur;
	return cur;
}
int main(int argc, char const *argv[])
{
	int data[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(data) / sizeof(int);
	llink list = NULL;
	int i;
	for (i = 0; i < size; i++)
		insert_list(&list, data[i]);
	display_list(list);
	reverse_recursive(&list, list);
	display_list(list);
	system("pause");
	return 0;
}*/