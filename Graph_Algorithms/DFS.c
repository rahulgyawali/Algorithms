#include <stdio.h>
#include <stdlib.h>

struct Stack {

	int* arr;
	int top;
	int size;
};

struct Stack* create (int size) 
{
	struct Stack* stack = NULL;

	stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->arr = (int*)malloc(sizeof(int)*size);	
	stack->size = size - 1;

	return stack;
}

int empty (struct Stack* stack)
{

	return (stack->top == -1);
}

int full (struct Stack* stack)
{

	return (stack->top > stack-> size);
}

void push (struct Stack* stack,int x)
{
	if (!full(stack)) {
		
		stack->top = stack->top + 1;
		stack->arr[stack->top] = x;
		
	}
}

int pop(struct Stack* stack)
{
	if (!empty(stack)) {

		int x;
	
		x = stack->arr[stack->top];
		stack->top  = stack->top - 1;
		
		return x;
	}	
}

void dfs (int s,int g[][1000],int state[],struct Stack* stack,int v)
{
	int i;
	int x;

	push(stack,s);										//Push Source node in Stack
	printf("DFS \n");
	
	while (!empty(stack)) {

		x = pop(stack);

		if (state[x] ==  -1) {

			printf("%d ",x);
			state[x] = 1;
		}

		for (i = 0; i < v; i++) {
	
			if ((g[x][i] == 1) && (state[i] == -1)) {

				push(stack,i);
			
			}
	
		}
			
	}
	printf("\n");
}

int main()
{
	int max;
	int v;
	int e;
	int i;
	int j;
	int x;
	int y;
	int s;
	int g[1000][1000];    							//Adjancency Matrix 'g'of int of  1000x1000

	scanf("%d %d",&v,&e);

	for (i = 0; i < v; i++) {

		for (j = 0; j < v ; j++) {

			g[i][j] = 0;
		}
	}

	
	for (i = 0; i < e; i++) {

		scanf("%d %d",&x,&y);						//Nodes with Edges in Undirected Graph

		g[x][y] = 1;
		g[y][x] = 1;
	}

	scanf("%d",&s);								//Take 's' as a source node

	int state[v];

	for (i = 0; i < v; i++) {
	
		state[i] = -1;							//All Nodes are Unvisited initially
	}

	struct Stack* stack = NULL;
	stack = create(v);
	
	dfs(s,g,state,stack,v);

	return 0;
}
