#include "../../includes/graph.h"
#include "../../../queue/includes/queue.h"
#include <stdio.h>

void BFS(graph* g, int nvertex, int src, int* visited){
	// creating queue
	queue _q;
	queue* q = &_q;
	queue_initialize(q);
	
	// add src to queue
	queue_enqueue(q, src + 1);
	while(!queue_empty(q)){
		int c = queue_front(q);
		queue_dequeue(q);
		if(!visited[c - 1]){
			visited[c - 1] = 1;
			printf("%d ", c);
			for(int i = 0; i < g -> adjacency[c - 1].edges -> size; i++){
				int e = g -> adjacency[c - 1].edges -> contents[i] -> destination -> index;
				if(!visited[e - 1]){
					queue_enqueue(q, e);
				}
			}
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
	printf("BFS sequence: ");
	BFS(g, vertices, 0, visited);
	printf("\n");

	graph_destroy(g, vertices);
}
