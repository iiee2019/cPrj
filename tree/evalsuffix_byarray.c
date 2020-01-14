/*
#include <stdio.h>
#include <stdlib.h>

int sp;

int findposition_infix(int *seq,int head,int rear,int target) {
	int i;
	for (i=rear-1;i>=0;i--){
		if (seq[i] == target)
			return i;
		return -1;
	}
}
void create_suffix(int *prefix,int* infix,int prefixhead,int prefixrear,int infixhead,int infixrear,int *suffix){
	if (prefixrear - prefixhead < 1)
		return;
	int root_val = prefix[prefixhead];
	suffix[sp--] = root_val;

	int root_position_infix = findposition_infix(infix, infixhead, infixrear, root_val);
	int split_prefix = root_position_infix - infixhead + prefixhead + 1;

	//rightsubtree
	create_suffix(prefix, infix, split_prefix, prefixrear, root_position_infix + 1, infixrear, suffix);
	//leftsubtree:
	create_suffix(prefix, infix, prefixhead + 1, split_prefix, infixhead, root_position_infix, suffix);
}*/