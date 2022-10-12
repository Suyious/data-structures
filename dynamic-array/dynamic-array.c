#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic_array vector;

struct dynamic_array {
	int size;
	int capacity;
	int* content;
};

void vector_initialize(vector* v){
	v -> size = 0;
	v -> capacity = 0;
	v -> content = NULL;
}

void vector_reallocate(vector* v){
	if(v -> capacity == 0){
		v -> content = malloc(sizeof(int));
		v -> capacity = 1;
	} else {
		v -> content = realloc(v -> content, sizeof(int) * ( v -> capacity * 2 ));
		v -> capacity *= 2;
	}
}

void vector_push_back(vector* v, int data){
	if(++(v -> size) > v -> capacity){
		vector_reallocate(v);
	}
	v -> content[v -> size - 1] = data;
}

void vector_pop_back(vector* v){
	if(v -> size > 0){
		(v -> size)--;
	}
}

int vector_at(vector* v, int index){
	return v -> content[index];
}

void vector_destroy(vector* v){
	free(v -> content);
}

int main(){
	vector _v;
	vector* v = &_v;

	vector_initialize(v);
	for(int i = 0; i < 10; i++){
		vector_push_back(v, i);
	}

	for(int i = 0; i < v -> size; i++){
		printf("%d ", vector_at(v, i));
	} printf("\n");

	printf("size: %d capacity: %d", v -> size, v -> capacity);
	vector_destroy(v);
	return 0;
}
