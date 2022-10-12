#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* next;
};

/*
 * LINKED LIST IMPLEMENTATION OF STACK <int>
 * */
typedef struct stack {
	node* top;
} stack;

void stack_initialize(stack* s);
void stack_push(stack* s, int data);
void stack_pop(stack* s);
node* stack_top(stack* s);
void stack_top_print(stack *s);
void stack_print(stack* s);

// Initializes an empty stack
void stack_initialize(stack* s){
	s -> top = NULL;
}

// pushes single integer to top of stack
void stack_push(stack* s, int data){
	node* temp = (node *) malloc(sizeof(node));
	temp -> data = data;
	temp -> next = s -> top;
	s -> top = temp;
}

// pops single integer from top of stack
void stack_pop(stack* s){
	if(s -> top){
		node* temp = s -> top;
		s -> top = s -> top -> next;
		free(temp);
	}
}

// returns node at top of stack
node* stack_top(stack* s){
	return s -> top;
}

// prints integer at top of stack
void stack_top_print(stack *s){
	if(s -> top){
		printf("%d\n", s -> top -> data);
	} else {
		printf("Stack Empty!");
	}
}

void stack_print(stack* s){
	while(s -> top != NULL){
		printf("%d ", s -> top -> data);
		stack_pop(s);
	}
}

int main(){
	stack s_t;
	stack *s = &s_t;
	s -> top = NULL;
	stack_push(s, 5);
	stack_push(s, 4);
	stack_push(s, 3);
	stack_push(s, 2);
	stack_push(s, 1);
	stack_push(s, 0);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	stack_pop(s);
	stack_top_print(s);
	return 0;
}
