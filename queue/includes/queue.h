#ifndef QUEUE_H
#define QUEUE_H

typedef struct node node;

struct node {
	int data;
	node* next;
	node* prev;
};

typedef struct queue {
	node* front;
	node* back;
} queue;


void queue_initialize(queue* q);
void queue_enqueue(queue* q, int data);
void queue_dequeue(queue* q);
int queue_front(queue* q);
void queue_print(queue* q);
int queue_empty(queue* q);


#endif
