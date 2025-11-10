#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], dist[MAX], visited[MAX], count, min, next, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0) ? INF : G[i][j];

    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for (count = 1; count < n - 1; count++) {
        min = INF;
        for (i = 0; i < n; i++)
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                next = i;
            }

        visited[next] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i] && min + cost[next][i] < dist[i])
                dist[i] = min + cost[next][i];
    }

    printf("\nShortest distances:\n");
    for (i = 0; i < n; i++)
        if (dist[i] != INF)
            printf("From %d to %d = %d\n", start + 1, i + 1, dist[i]);
        else
            printf("From %d to %d = -1\n", start + 1, i + 1);
}

int main() {
    int G[MAX][MAX], i, j, start;
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter start node: ");
    scanf("%d", &start);

    dijkstra(G, n, start - 1);
    return 0;
}