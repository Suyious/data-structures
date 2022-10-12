#include "includes/heap.h"

int main(){
	heap _h;
	heap* h = &_h;
	
	heap_max_initialize(h);

	heap_push(h, 70);
	heap_push(h, 40);
	heap_push(h, 45);
	heap_push(h, 50);
	heap_push(h, 30);
	heap_push(h, 20);
	heap_push(h, 10);

	heap_display(h);

	heap_pop(h);
	heap_display(h);

	heap_pop(h);
	heap_display(h);

	heap_pop(h);
	heap_display(h);

	heap_pop(h);
	heap_display(h);

	heap_pop(h);
	heap_display(h);

	heap_push(h, 500);
	heap_push(h, 20);
	heap_push(h, 50);

	heap_display(h);

}
