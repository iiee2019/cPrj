#pragma once
#ifndef  STACK_H
#define STACK_H

#define  STACK_TYPE int

void createStack(size_t size);

void push(STACK_TYPE val);

void pop();

STACK_TYPE top();

int isEmpty();

int isFull();

void destroyStack();
#endif