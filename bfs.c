#include <stdio.h>

#define QUEUE_SIZE 20
#define MAX 20

int queue[QUEUE_SIZE];
int queue_front, queue_end;
void enqueue(int v);
int dequeue();

void bfs(int Adj[MAX][MAX], int n, int source);

int main(void) {
	int adj[MAX][MAX];
	int n;
	int sv;
	printf("Enter no of vertex: ");
	scanf("%d",&n);
	printf("Enter %d vertices into matrix:\n", n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &adj[i][j]);
	printf("Enter starting vertex: ");
	scanf("%d", &sv);

	bfs(adj, n, sv);
}

void bfs(int adj[MAX][MAX], int n, int sv) {
	int i, j;

	int visited[MAX] = {};

	queue_front = 0;
	queue_end = 0;

	visited[sv] = 1;

	enqueue(sv);

	printf("%d ", sv);

	while(queue_front <= queue_end) {
		i = dequeue();

		for(j = 0; j <n; j++) {
			if(visited[j] == 0 && adj[i][j] == 1) {
				visited[j] = 1;

				enqueue(j);

				printf("%d ", j);
			}
		}
	}
	printf("\n");
}

void enqueue(int v) {
	queue[queue_end] = v;
	queue_end++;
}

int dequeue() {
	int index = queue_front;
	queue_front++;
	return queue[index];
}


