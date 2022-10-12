#include "includes/queue.h"
#include <stdio.h>

void queue_front_print(queue *q){
	if(q -> front){
		printf("%d\n", queue_front(q));
	} else {
		printf("Queue Empty!\n");
	}
}

int main(){
	queue _q;
	queue* q = &_q;
	queue_initialize(q);
	queue_enqueue(q, 1);
	queue_enqueue(q, 2);
	queue_enqueue(q, 3);

	queue_front_print(q);
	queue_dequeue(q);
	queue_front_print(q);
	queue_dequeue(q);
	queue_front_print(q);
	queue_dequeue(q);
	queue_front_print(q);
	return 0;
}
