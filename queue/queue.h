#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#define  QUEUE_TYPE  int /*队列元素的类型 */

void createQueue(size_t size);

void destroyQueue(void);
void insertToQueue(QUEUE_TYPE val);
void deleteFromQueue();
QUEUE_TYPE first();
int isEmpty();
int isFull();
#endif // !QUEUE_H

