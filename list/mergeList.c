/*

#include <stdio.h>
#include "list.h"

llink merge_list(llink list1,llink list2) {
	llink cur1 = list1;
	llink cur2 = list2;
	llink newList = NULL;
	llink selected = NULL;
	llink newList_cur = NULL;
	while (list1&&list2)
	{
		if (list1->val<list2->val) {
			selected = list1;
			list1=list1->next;
		}else{
			selected = list2;
			list2 = list2->next;
		}
		if (!newList){
			newList=selected;
			newList_cur = newList;
		}else{
			newList_cur->next = selected;
			newList_cur = newList_cur->next;
		}
	}
	if (list1)
	{
		if (!newList_cur)
			newList = list1;
		else
			newList_cur->next = list1;
	}
	if (list2)
	{
		if (!newList_cur)
			newList = list2;
		else
			newList_cur->next = list2;
	}
	return newList;
}
llink merge_list_recrusive(llink list1, llink list2) {
	if (list1&&list2)
	{
		if (list1->val < list2->val)
		{
			list1->next = merge_list_recrusive(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = merge_list_recrusive(list1, list2->next);
			return list2;
		}
	}
	else if (list1)
		return list1;
	else
		return list2;
}
int main(int argc,char const *argv[]) {
	int data1[] = {1,3,3,8,9,10};
	int size1 = sizeof(data1) / sizeof(int);
	int data2[] = {2,3,6,7,8,12,13};
	int size2 = sizeof(data2) / sizeof(int);

	llink list1 = NULL, list2 = NULL;
	for (int i = 0; i < size1; i++)
		insert_list(&list1, data1[i]);
	display_list(list1);
	for (int i = 0; i < size2; i++)
		insert_list(&list2, data2[i]);
	display_list(list2);
	//llink list3 = merge_list(list1, list2);
	llink list3 = merge_list_recrusive(list1, list2);
	display_list(list3);
	system("pause");
	return 0;
})
*/
