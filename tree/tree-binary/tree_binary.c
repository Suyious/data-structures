#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
	int data;
	node* left;
	node* right;
};

typedef struct tree_binary tree;
struct tree_binary{
	node* root;
};

int main(){
	tree _t;
	tree* t = &_t;
	t -> root = NULL;
	return 0;
}
