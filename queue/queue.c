#include <stdlib.h>
#include "includes/queue.h"

void queue_initialize(queue* q){
	q -> front = NULL;
	q -> back  = NULL;
}

void queue_enqueue(queue* q, int data){

	// initializing new node
	node* temp = (node *) malloc(sizeof(node));
	temp -> data = data;
	temp -> next = NULL;
	temp -> prev = q -> back;

	// if not last node , modify next to previous node
	if(q -> back) q -> back -> next = temp;

	// if first node, handle front
	if(q -> front == NULL) q -> front = temp;

	// inserting node at back
	q -> back = temp;
}

void queue_dequeue(queue* q){
	if(q -> front){
		node* temp = q -> front;
		q -> front = temp -> next;
		if(q -> front) q -> front -> prev = NULL;
		free(temp);
	}
}

int queue_front(queue* q){
	return q -> front -> data;
}

int queue_empty(queue* q){
	if(q -> front) return 0;
	return 1;
}

