#include <stdio.h>
#include "../../includes/graph.h"

void DFS(graph* g, int nvertex, int src, int* visited){
	visited[src] = 1;
	printf("%d ", src + 1);
	for(int i = 0; i < g -> adjacency[src].edges -> size; i++){
		int e = g -> adjacency[src].edges -> contents[i] -> destination -> index;
		if(!visited[e - 1]){
			DFS(g, nvertex, e - 1, visited);
		}
	}
}

int main(){
	// User Input as a variable
	const int input[][3] = {
		{1, 2, 28},
		{1, 6, 10},
		{2, 3, 16},
		{2, 7, 14},
		{3, 4, 12},
		{4, 5, 22},
		{4, 7, 18},
		{5, 6, 25},
		{5, 7, 24},
	};

	graph _g;
	graph* g = &_g;

	int vertices = 7, edges = 9;
	graph_initialize(g, vertices);
	graph_populate_from_input(g, edges, input);

	// graph_print_adjacency_list_repr(g ,vertices);

	int visited[vertices];
	for(int i = 0; i < vertices; i++) visited[i] = 0;
	printf("DFS sequence: ");
	DFS(g, vertices, 0, visited);
	printf("\n");

	graph_destroy(g, vertices);
}
