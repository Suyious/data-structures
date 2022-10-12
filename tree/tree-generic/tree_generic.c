#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct nodelist nodelist;
typedef struct tree_generic tree;

struct node {
	int data;
	nodelist* children;
};

struct nodelist {
	int size;
	int capacity;
	node** contents;
};

struct tree_generic {
	node* root;
};

node* node_create_new(int data){
	node* temp = malloc(sizeof(node));
	temp -> data = data;
	temp -> children = NULL;
	return temp;
}

void nodelist_initialize(nodelist* v){
	v -> size = 0;
	v -> capacity = 0;
	v -> contents = NULL;
}

void nodelist_reallocate(nodelist* v){
	if(v -> capacity == 0){
		v -> contents = malloc(sizeof(node*));
		v -> capacity = 1;
	} else {
		v -> contents = realloc(v -> contents, sizeof(node*) * ( v -> capacity * 2 ));
		v -> capacity *= 2;
	}
}

void nodelist_push_back(nodelist* v, int data){
	if(++(v -> size) > v -> capacity){
		nodelist_reallocate(v);
	}
	v -> contents[v -> size - 1] = node_create_new(data);
}

void nodelist_pop_back(nodelist* v){
	if(v -> size > 0){
		(v -> size)--;
	}
}

void tree_initialize(tree *t){
	t -> root = NULL;
}

void tree_add_child(node* parent, int data){
	if(parent -> children == NULL){
		parent -> children = malloc(sizeof(nodelist));
	}
	nodelist_push_back(parent -> children, data);
}

node* tree_get_child(node* parent, int index){
	return parent -> children -> contents[index];
}

void indent(int levels, int ends, int flags){
	char* indentation[levels];
	for(int i = levels - 1; i >= 0; i--){
		if(i == levels - 1){
			if(ends) indentation[i] = "└─";
			else indentation[i] = "├─";
		} else {
			if(flags % 2 == 0) indentation[i] = "  ";
			else indentation[i] = "│ ";
		}
		flags = (flags >> 1);
	}
	for(int i = 0; i < levels; i++){
		printf("%s", indentation[i]);
	}
}

void traverse(node* n, int levels, int flags){
	printf("%d\n", n -> data);
	if(n -> children){
		for(int i = 0; i < n -> children -> size; i++){
			int ends = i == n -> children -> size - 1;
			flags = (flags << 1);
			if(!ends) flags += 1;
			indent(levels + 1, ends, flags);
			traverse(n -> children -> contents[i], levels + 1, flags);
			flags = (flags >> 1);
		}
	}
}

void tree_destroy(node* root){
	for(int i = 0; i < root -> children -> size; i++){
		free(root -> children -> contents[i]);
	}
	free(root -> children);
	free(root);
}

int main(){

	tree _t;
	tree* t = &_t;

	tree_initialize(t);

	t -> root = node_create_new(1);
	node* root = t -> root;

	tree_add_child(root, 2);
	node* child0 = tree_get_child(root, 0);
	tree_add_child(child0, 6);
	tree_add_child(child0, 7);
	node* child01 = tree_get_child(child0, 1);
	tree_add_child(child01, 12);

	tree_add_child(root, 3);
	node* child1 = tree_get_child(root, 1);
	tree_add_child(child1, 8);
	node* child10 = tree_get_child(child1, 0);
	tree_add_child(child10, 13);
	tree_add_child(child10, 14);

	tree_add_child(root, 4);
	node* child2 = tree_get_child(root, 2);
	tree_add_child(child2, 9);
	tree_add_child(child2, 10);
	tree_add_child(child2, 11);

	tree_add_child(root, 5);
	node* child3 = tree_get_child(root, 3);
	tree_add_child(child3, 12);
	node* child30 = tree_get_child(child3, 0);
	tree_add_child(child30, 13);
	node* child300 = tree_get_child(child30, 0);
	tree_add_child(child300, 14);
	tree_add_child(child30, 15);
	tree_add_child(child30, 16);
	node* child302 = tree_get_child(child30, 2);
	tree_add_child(child302, 17);

	traverse(root, 0, 0);

	tree_destroy(root);

	nodelist _n;
	nodelist* n = &_n;

	return 0;
}
