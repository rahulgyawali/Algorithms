#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct list {

	struct node* start;
};

struct graph {

	int v;
	struct list* array;
};

struct node* newnode(int x)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = x;
	new->link = NULL;

	return new;
}
struct graph* create (int V) 
{
	int i;
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	g->v = V;
	g->array = (struct list*)malloc(V*sizeof(struct list));

	for (i = 0; i < V; i++) {

		g->array[i].start = NULL;
	}

	return g;
}

void add(struct graph* g,int s,int d)
{
	struct node* p = newnode(d);
	p->link = g->array[s].start;
	g->array[s].start = p;

	struct node* k = newnode(s);
	k->link = g->array[d].start;
	g->array[d].start = k;


} 

void print(struct graph* g)
{
	int v;

	for (v = 0; v < g->v; v++) {

		struct node* tmp = g->array[v].start;
		printf("Vertex %d: ",v);

		while (tmp) {

			printf("%d ",tmp->data);
			tmp = tmp->link;
		}
		
		printf("\n");
	}

	printf("\n");
}

int  main()
{

	struct graph* g = NULL;
	g = create(5);

	add(g,0,1);
	add(g,0,4);
	add(g,1,2);
	add(g,1,3);
	add(g,1,4);
	add(g,2,3);
	add(g,3,4);

	print(g);

	return 0;
}
