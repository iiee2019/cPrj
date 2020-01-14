#pragma once
#ifndef TREE_H
#define  TREE_H

#define  TREE_TYPE int

void insert(TREE_TYPE val);

TREE_TYPE* find(TREE_TYPE val);

void pre_Order_Traverse(void(*callback)(TREE_TYPE val));
#endif