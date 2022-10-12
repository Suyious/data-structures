#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

typedef struct tree_binary_complete tree;

struct tree_binary_complete {
	int size;
	int capacity;
	int* contents;
};

void tree_initialize(tree* t);
void tree_reallocate(tree* t);
void tree_add_node(tree* t, int data);
void tree_remove_node(tree* t);
void tree_destroy(tree* t);
int tree_left_child(tree* t, int parent_index);
int tree_right_child(tree* t, int parent_index);

#endif
