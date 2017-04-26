
#include <stdio.h>
#include <stdlib.h>

struct item {

    int value;
    float weight;
};

struct node
{
    
    int level;
    int profit;
    int bound;
    float weight;
};

struct Queue{
    
    int front;
    int rear;
    int size;   
    struct node *a;
};



void swap(int* a,int *b)
{   
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(float* a,float* b)
{
    float x;

    x = *a;
    *a = *b;
    *b = x;
}

int partition(struct item a[],int start,int end)
{
    double pivot;
    int pindex;
    int i;
    
    pindex = start;
    pivot = (float)((a[end].value) /(a[end].weight)) ;
    
    for (i = start; i < end; i++) {
        
        if (((float)((a[i].value)/(a[i].weight))) >= pivot) {
            
            swap(&a[i].value,&a[pindex].value);
            swap2(&a[i].weight,&a[pindex].weight);
            pindex = pindex + 1;
    
        }
    }

    swap(&a[end].value,&a[pindex].value);
    swap2(&a[end].weight,&a[pindex].weight);
    
    return pindex;
}

void quicksort(struct item a[],int start,int end)
{
    if (start < end) {
        
        int pindex;
        
        pindex = partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
    
    }
}


struct Queue *create(int capacity)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = capacity -1;
    queue->a = (struct node *)malloc(sizeof(struct node) * (capacity));
    
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

void eq(struct Queue *queue,struct node x)
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

struct node dq(struct Queue *queue)
{
    if(!Empty(queue)) {

        struct node item = queue->a[queue->front];
        queue->front = (queue->front + 1);
        return item;
    }
}

int bound(struct node u, int n, int W, struct item arr[])
{
    // if weight overcomes the knapsack capacity, return
    // 0 as expected bound
    if (u.weight >= W)
        return 0;
 
    // initialize bound on profit by current profit
    int profit_bound = u.profit;
 
    // start including items from index 1 more to current
    // item index
    int j = u.level + 1;
    int totweight = u.weight;
 
    // checking index condition and knapsack capacity
    // condition
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
 
    // If k is not n, include last item partially for
    // upper bound on profit
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                                         arr[j].weight;
 
    return profit_bound;
}
 
// Returns maximum profit we can get with capacity W
int knapsack(int W, struct item arr[], int n)
{
    
   quicksort(arr,0,n-1);
 
    // make a queue for traversing the node
//    queue<Node> Q;

    struct Queue* q = NULL;
    int y = 2*n;
    q = create(y);

    struct node u, v;
 
    // dummy node at starting
    u.level = -1;
    u.profit = u.weight = 0;
    eq(q,u);
 
    // One by one extract an item from decision tree
    // compute profit of all children of extracted item
    // and keep saving maxProfit
    int maxProfit = 0;
    while (!Empty(q))
    {
        // Dequeue a node
        u = dq(q);
        
 
        // If it is starting node, assign level 0
        if (u.level == -1)
            v.level = 0;
 
        // If there is nothing on next level
        if (u.level == n-1)
            continue;
 
        // Else if not last node, then increment level,
        // and compute profit of children nodes.
        v.level = u.level + 1;
 
        // Taking current level's item add current
        // level's weight and value to node u's
        // weight and value
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
 
        // If cumulated weight is less than W and
        // profit is greater than previous profit,
        // update maxprofit
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
 
        // Get the upper bound on profit to decide
        // whether to add v to Q or not.
        v.bound = bound(v, n, W, arr);
 
        // If bound value is greater than profit,
        // then only push into queue for further
        // consideration
        if (v.bound > maxProfit)
            eq(q,v);
 
        // Do the same thing,  but Without taking
        // the item in knapsack
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            eq(q,v);
    }
 
    return maxProfit;
}
 

int main()
{
    int i;
    int n;
    int w;
    float max;

    printf("No.of Items and Max Weight\n");
    scanf("%d %d",&n,&w);
    
    struct item arr[n];

    for (i = 0; i < n; i++) {
    
        scanf("%d %f",&arr[i].value,&arr[i].weight);

    }

    max = knapsack(w,arr,n);

    printf("%f is Max\n",max);

 
    return 0;
}
