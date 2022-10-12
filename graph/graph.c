#include <stdio.h>
#include <stdlib.h>
#include "includes/graph.h"

// Increases capacity of dynamic array `edgelist`
// when edgelist needs to store after fully filled.
void edgelist_reallocate(edgelist* e){
	if(e -> capacity == 0){
		e -> contents = malloc(sizeof(int));
		e -> capacity = 1;
	} else {
		e -> contents = realloc(e -> contents, sizeof(int) * ( e -> capacity * 2 ));
		e -> capacity *= 2;
	}
}

// Pushes a new `edge` initialized from `vertex` 'source'
// to `vertex` 'destination' weighted 'weight'
// at the end of `edgelist` 'e'
void edgelist_push_back(edgelist* e, vertex* source, vertex* destination, int weight){
	if(++(e -> size) > e -> capacity){
		edgelist_reallocate(e);
	}
	e -> contents[e -> size - 1] = edge_new(source, destination, weight);
}

// Removes the last `edge` from the `edgelist` 'e'
void edgelist_pop_back(edgelist* e){
	if(e -> size > 0){
		(e -> size)--;
	}
}

edge* edge_new(vertex* source, vertex* destination, int weight){
	edge* temp = malloc(sizeof(edge));
	temp -> source = source;
	temp -> destination = destination;
	temp -> weight = weight;
	return temp;
}

// Initializes a `graph` 'g' with 'n' vertices
void graph_initialize(graph* g, int n){
	g -> adjacency = malloc(sizeof(vertex) * n);
	for(int i = 0; i < n; i++){
		vertex* vi = &(g -> adjacency[i]);
		vi -> index = i + 1;
		vi -> edges = (edgelist*) malloc(sizeof(edgelist));
		vi -> edges -> size = 0;
		vi -> edges -> capacity = 0;
		vi -> edges -> contents = NULL;
	}
}

void graph_destroy(graph* g, int n){
	for(int i = 0; i < n; i++){
		vertex* vi = &(g -> adjacency[i]);
		free(vi -> edges);
	}
	free(g -> adjacency);
}

void graph_print_adjacency_list_repr(graph* g, int vertices){
	for(int i = 0; i < vertices; i++){
		vertex* vi = &(g -> adjacency[i]);
		int ei = vi -> edges -> size;
		if(ei){
			printf("%d: [", i + 1);
			for(int j = 0; j < ei; j++){
				printf("%d, ", vi -> edges -> contents[j] -> source -> index);
				printf("%d, ", vi -> edges -> contents[j] -> destination -> index);
				printf("%d", vi -> edges -> contents[j] -> weight);
				printf("]");
				if(j != ei - 1) printf(", [");
			} printf("\n");
		}
	}
}

void graph_populate_from_input(graph* g, int nedges, const int input[][3]){
	for(int i = 0; i < nedges; i++){
		vertex* source = &(g -> adjacency[input[i][0] - 1]);
		vertex* destination = &(g -> adjacency[input[i][1] - 1]);
		edgelist_push_back(source -> edges, source, destination, input[i][2]);
		edgelist_push_back(destination -> edges, destination, source, input[i][2]);
	}
}
