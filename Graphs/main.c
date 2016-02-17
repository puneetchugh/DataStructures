#include<stdio.h>
#include<stdlib.h>


typedef struct node{

	int dest;
	struct node *next;
}adj_list_node;

typedef struct adj_list{
	
	adj_list_node *head;
}adj_list;

typedef struct graph{

	int number_of_nodes;
	adj_list* list;
}Graph;


adj_list_node* add_a_node(int dest){
	
	adj_list_node *new_node = (adj_list_node*) malloc(sizeof(adj_list_node));

	new_node->dest = dest;
	new_node->next = NULL;

	return new_node;
}

Graph* add_a_graph(int number_of_nodes){

	Graph *graph = (Graph*) malloc(sizeof(Graph));
	graph->number_of_nodes = number_of_nodes;
	graph->list = (adj_list*) malloc(number_of_nodes * sizeof(adj_list));

	int counter = 0;

	for(counter = 0; counter < number_of_nodes; counter++){
		
		graph->list[counter].head = NULL;
	}
	return graph;

}

void add_edge(Graph * graph, int src, int dest){

	adj_list_node *new_node = add_a_node(dest);
	new_node->next = graph->list[src].head;
	graph->list[src].head = new_node;

	new_node = add_a_node(src);
	new_node->next = graph->list[dest].head;
	graph->list[dest].head = new_node;
	
}

void printGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->number_of_nodes; ++v)
    {
        adj_list_node* pCrawl = graph->list[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


int main(){
   // create the graph given in above fugure
    int V = 5;
    Graph* graph = add_a_graph(V);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
	
	return 0;
}
