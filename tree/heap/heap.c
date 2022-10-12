#include <stdio.h>
#include <stdlib.h>
#include "includes/heap.h"

void heap_max_initialize(heap* h){
	h -> size = 0;
	h -> capacity = 0;
	h -> max = 1;
	h -> contents = NULL;
}

void heap_min_initialize(heap* h){
	h -> size = 0;
	h -> capacity = 0;
	h -> max = 0;
	h -> contents = NULL;
}

void heap_swap(heap* h, int x, int y){
	int temp = h -> contents[x];
	h -> contents[x] = h -> contents[y];
	h -> contents[y] = temp;
}

int heap_parent(int child_index){
	// (for 1-based indexing) parent of i is i / 2
	// (for 0-based indexing) parent of i is (i + 1) / 2 - 1
	return (child_index + 1) / 2 - 1;
}

int heap_left_child(heap* h, int parent_index){
	// (for 1-based indexing) left child of i is 2 * i
	// (for 0-based indexing) left child of i is 2 * (i + 1) - 1
	return 2 * (parent_index + 1) - 1;
}

int heap_right_child(heap* h, int parent_index){
	// (for 1-based indexing) right child of i is 2 * i + 1
	// (for 0-based indexing) right child of i is 2 * (i + 1) + 1 - 1
	return 2 * (parent_index + 1);
}

void heap_reallocate(heap* h){
	if(h -> capacity == 0){
		h -> contents = (int*) malloc(sizeof(int));
		h -> capacity = 1;
	} else {
		h -> contents = (int*) realloc(h -> contents, sizeof(int) * ( h -> capacity * 2 ));
		h -> capacity *= 2;
	}
}

void heap_heapify_insertion(heap *h){
	int i = h -> size - 1;
	while(i > 0){
		int parent = heap_parent(i);
		int check = h -> contents[parent] < h -> contents[i];
		if(!h -> max) check = !check;
		if(check){
			heap_swap(h, parent, i);
			i = parent;
		} else return;
	}
}

void heap_push(heap* h, int data){
	if(++(h -> size) > h -> capacity){
		heap_reallocate(h);
	}
	h -> contents[h -> size - 1] = data;
	heap_heapify_insertion(h);
}

void heap_heapify_deletion(heap* h){
		int i = 0;
		while((heap_left_child(h, i)) < h -> size){
			int left = heap_left_child(h, i);
			int right = heap_right_child(h, i);
			int prior = left;
			if(right < h -> size){
				if(h -> max) prior = h -> contents[left] > h -> contents[right] ? left : right;
				else prior = h -> contents[left] < h -> contents[right] ? left : right;
			}
			int check = h -> contents[prior] > h -> contents[i];
			if(!h -> max) check = !check;
			if(check){
				heap_swap(h, prior, i);
				i = prior;
			} else return;
		}

}

void heap_pop(heap* h){
	if(h -> size > 0){
		h -> contents[0] = h -> contents[h -> size - 1];
		(h -> size)--;
		heap_heapify_deletion(h);
	}
}

int heap_top(heap* h){
	return h -> contents[0];
}

void heap_destroy(heap* h){
	free(h -> contents);
}

void heap_display(heap* h){
	for(int i = 0; i < h -> size; i++){
		printf("%d ", h -> contents[i]);
	} printf("\n");
}
