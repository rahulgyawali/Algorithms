#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
	
	int front;
	int rear;
	int size;	
	int *a;
};

struct Queue *create(int capacity)
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = -1;
	queue->size = capacity -1;
	queue->a = (int *)malloc(sizeof(int) * (capacity));
	
	return queue;
}

int  Full(struct Queue *queue)
{
	return (queue->size < queue->rear);
}

int Empty(struct Queue *queue)
{
	return((queue->front == -1) || (queue->front > queue->rear)) ;
}

void eq(struct Queue *queue,int x)
{
	if (((queue->front == -1) && (queue->rear == -1) )) {

		queue->front = 0;
		queue->rear = 0;
		queue->a[queue->rear] = x;

	}else if (!Full(queue)) {

		queue->rear = queue->rear + 1;
		queue->a[queue->rear] = x;
	}
}

int dq(struct Queue *queue)
{
	if(!Empty(queue)) {

		int item = queue->a[queue->front];
		queue->front = (queue->front + 1);
		return item;
	}
}

void bfs (int s, struct Queue* queue,int state[],int parent[],int distance[],int g[][1000],int v)
{

	int i;
	
	eq(queue,s);  								//Enqueue Source 's'	
	printf("INSIDE BFS\n");
	while (!Empty(queue)) {

		int x;
		x = dq(queue);							//Pop Out a node From Queue
		state[x] = 1;							//Mark it as Visited
		printf("%d ",x);
				
		for (i = 0; i < v; i++) {

			if (g[x][i] == 1) {  				//Look for Neighbour nodes if there is one

				if (state[i] == -1) { 			//If the neighbour is unvisited then push it on queue and marks as visiting node i.e. 0
			
					state[i] = 0;
					distance[i] = distance[x] + 1;
					parent[i] = x;
					eq(queue,i);
				}
			}
		}

		printf("\n");
	}
}

int main()
{
	int i;
	int v;
	int e;
	int x;
	int y;
	int s;
	int j;

	scanf("%d %d",&v,&e); 						//Take Vertices and Edges

	int g[1000][1000];

	for (i = 0; i <v ; i++) {           		//Initialiaze them

		for (j = 0; j < v; j++) {
		
			g[i][j] = 0;
		}
	}

	for (i = 0; i < e; i++) { 
												//Take nodes which are connected by an edge  
		scanf("%d %d",&x,&y);
		g[x][y] = 1;							//Undirected Graph
		g[y][x] = 1;
	}

	scanf("%d",&s);								//Take Source node 's'

	int state [v];
	int distance [v];
	int parent [v];

	for (i = 0; i <v ;i++) {

		state[i] = -1; 							//Mark all the nodes as unvisited i.e. -1
		distance[i] = INT_MAX;					//Distance from Source is Infinite
		parent[i] = 0;							//Parent is NIL/0 for all vertices initially
	}

	state[s] = 0;                 				//State of Source 's' is Kept as Currently Visiting node i.e. 0
	distance[s] = 0;
	parent[s] = -1;

	struct Queue* queue = NULL;
	queue = create(v);
	bfs(s,queue,state,parent,distance,g,v);

	/*for (i = 0; i < v; i++) {

		printf("%d's parent is %d\n",i,parent[i]);
		printf("%d's distance from %d is %d\n",i,s,distance[i]);
	}*/

	return 0;
}
