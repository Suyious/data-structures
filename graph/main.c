#include "./includes/graph.h"

int main(){

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

	graph_print_adjacency_list_repr(g, vertices);

	graph_destroy(g, vertices);

	return 0;
}
