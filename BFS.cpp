#include<stdio.h>

#define WHITE -1
#define GRAY 0
#define BLACK 1
#define CONNECTED 1
#define DISCONNECTED 0
#define SIZE 100

int graph[SIZE+1][SIZE+1], color[SIZE+1], d[SIZE+1], p[SIZE+1];
int queue[SIZE], head, tail;
int nodes, edges;

void initialize_queue()
{
	head = tail = 0;
}

void enqueue(int node)
{
	queue[tail++] = node;
}

int dequeue()
{
	return queue[head++];
}

bool queue_empty()
{
	return head == tail;
}

void BFS(int source, int nodes)
{
	// initially mark all nodes as undiscovered
	for(int i=1; i<=nodes; i++)
		color[i] = WHITE;

	// inserting source into the queue and modifying relevant values
	enqueue(source);
	color[source] = GRAY;
	d[source] = 0;
	p[source] = -1;


	while(!queue_empty())	// repeat until queue is empty
	{
		int u = dequeue();
		printf("-> %d ", u);	// print nodes in visiting sequence

		for(int v=1; v<=nodes; v++)	// check all nodes for neighbour
		{
			if(graph[u][v] == CONNECTED)	// check connected node
			{
				if(color[v] == WHITE)	// check if node is undiscovered
				{
					color[v] = GRAY;	// mark node as discovered
					d[v] = d[u] + 1;
					p[v] = u;
					enqueue(v);			// insert neighbour into the queue
				}
			}
		}
		color[u] = BLACK;	// mark node as finished
	}
	printf("\n");
}


void main()
{
	int x, y;

	puts("No. of nodes: ");
	scanf("%d", &nodes);

	// initializing graph using no. of nodes
	for(int i=1; i<=nodes; i++)
		for(int j=1; j<=nodes; j++)
			graph[i][j] = DISCONNECTED;

	puts("No. of edges: ");
	scanf("%d", &edges);

	// take edge info from user and init. graph
	for(int i=1; i<=edges; i++)
	{
		printf("Enter edges %d: ", i);
		scanf("%d %d", &x, &y);
		graph[x][y] = graph[y][x] = CONNECTED;
	}


	initialize_queue();	// initialize queue before using
	BFS(1, nodes);		// call bfs for graph

	// showing parent information for each node
	for(int i=1; i<=nodes; i++)
		printf("%d parent: %d\n", i, p[i]);
}
