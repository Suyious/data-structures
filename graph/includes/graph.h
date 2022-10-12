#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge edge;
typedef struct edgelist edgelist;
typedef struct vertex vertex;
typedef struct graph graph;

struct edgelist {
	int size;
	int capacity;
	edge** contents;
};

struct vertex {
	int index;
	edgelist* edges;
};

struct edge {
	vertex* source;
	vertex* destination;
	int weight;
};

struct graph{
	vertex* adjacency;
};

void edgelist_reallocate(edgelist* e);
void edgelist_push_back(edgelist* e, vertex* source, vertex* destination, int weight);
void edgelist_pop_back(edgelist* e);
edge* edge_new(vertex* source, vertex* destination, int weight);
void graph_initialize(graph* g, int n);
void graph_destroy(graph* g, int n);
void graph_print_adjacency_list_repr(graph* g, int vertices);
void graph_populate_from_input(graph* g, int nedges, const int input[][3]);

#endif
