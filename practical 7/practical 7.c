#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n;

// BFS Function
void BFS(int start) {
    int i;
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 1; i <= n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Function
void DFS(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;

    for (i = 1; i <= n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    int i, j, start;

    printf("Enter number of nodes in graph: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 or 1):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    // BFS Traversal
    for (i = 1; i <= n; i++) visited[i] = 0;
    BFS(start);

    // DFS Traversal
    for (i = 1; i <= n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}