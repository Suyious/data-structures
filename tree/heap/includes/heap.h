#ifndef HEAP_H
#define HEAP_H

typedef struct priority_queue heap;

struct priority_queue {
	int size;
	int capacity;
	char max;
	// max = 1 for maximum priority queue
	// max = 0 for minimum priority queue
	int* contents;
};

void heap_max_initialize(heap* h);
void heap_min_initialize(heap* h);
int heap_parent(int child_index);
int heap_left_child(heap* h, int parent_index);
int heap_right_child(heap* h, int parent_index);
void heap_reallocate(heap* h);
void heap_push(heap* h, int data);
void heap_pop(heap* h);
int heap_top(heap* h);
void heap_destroy(heap* h);
void heap_display(heap* h);

#endif
