/*
#include <stdio.h> 
#include <stdlib.h>
#include "list.h"

void insert_list(llink* list, int item) {
	llink newlist = malloc(sizeof(struct List));
	if (!newlist)
	{
		return;
	}
	newlist->val = item;
	newlist->next = NULL;
	if (!*list)
	{
		*list = newlist;
		return;
	}
	llink cur = *list;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = newlist;
}

void display_list(llink list) {
	while (list)
	{
		printf("%d\t", list->val);
		list = list->next;
	}
	printf("\n");
}
llink insert_list_recursive(llink list, int item) {
	if (!list)
	{
		llink newList = malloc(sizeof(struct List));
		if (!newList) {
			return newList;
		}
		newList->val = item;
		newList->next = NULL;
		return newList;
	}
	list->next = insert_list_recursive(list->next, item);
	return list;
}
llink in_li_rec(llink list, int item) {
	if (!list)
	{
		llink newLN=malloc(sizeof(struct List));
		if (!newLN)
		{
			return newLN;
		}
		newLN->val = item;
		newLN->next = NULL;
		return newLN;
	}
	list->next = in_li_rec(list->next, item);
	return list;
}
llink search_list(llink list, int item) {
	llink cur = NULL;
	while (list&&!cur)
	{
		if (list->val==item)
			cur = list;
		list = list->next;
	}
	return cur;
}
int list_length(llink list) {
	int length = 0;
	while (list)
	{
		length++;
		list = list->next;
	}
	return length;
}*/