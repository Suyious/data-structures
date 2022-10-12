#include <stdio.h>
#include <stdlib.h>
#include "includes/tree-binary-complete.h"

void tree_initialize(tree* t){
	t -> size = 0;
	t -> capacity = 0;
	t -> contents = NULL;
}

void tree_reallocate(tree* t){
	if(t -> capacity == 0){
		t -> contents = (int *) malloc(sizeof(int));
		t -> capacity = 1;
	} else {
		t -> contents = (int *) realloc(t -> contents, sizeof(int) * ( t -> capacity * 2 ));
		t -> capacity *= 2;
	}
}

void tree_add_node(tree* t, int data){
	if(++(t -> size) > t -> capacity){
		tree_reallocate(t);
	}
	t -> contents[t -> size - 1] = data;
}

void tree_remove_node(tree* t){
	if(t -> size > 0){
		(t -> size)--;
	}
}

void tree_destroy(tree* t){
	free(t -> contents);
}

int tree_root(tree* t){
	return t -> contents[0];
}

int tree_left_child_index(tree* t, int parent_index){
	return 2 * (parent_index + 1) - 1;
}

int tree_right_child_index(tree* t, int parent_index){
	return 2 * (parent_index + 1);
}

int tree_left_child(tree* t, int parent_index){
	return t -> contents[tree_left_child_index(t, parent_index)];
}

int tree_right_child(tree* t, int parent_index){
	return t -> contents[tree_right_child_index(t, parent_index)];
}

int main(){
	tree _t;
	tree* t = &_t;
	
	tree_initialize(t);
	tree_add_node(t, 1);
	tree_add_node(t, 2);
	tree_add_node(t, 3);
	tree_add_node(t, 4);
	tree_add_node(t, 5);
	tree_add_node(t, 6);

	printf("Tree has %d nodes.\n", t -> size);

	for(int i = 0; i < t -> size; i++){
		printf("%d: %d\n", i, t -> contents[i]);
	}

	printf("Root: %d\n", tree_root(t));
	printf("Left Child: %d\n", tree_left_child(t, 0));
	printf("Right Child: %d\n", tree_right_child(t, 0));
	printf("Left Child: %d\n", tree_left_child(t, tree_left_child_index(t, 0)));
	printf("Right Child: %d\n", tree_right_child(t, tree_left_child_index(t, 0)));

	return 0;
}
