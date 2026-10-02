#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int vertices;
void createGraph()
{
    int edges, u, v, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
void displayGraph()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
void BFS(int start)
{
    int i, u;
    for (i = 0; i < vertices; i++)
        visited[i] = 0;
    front = rear = -1;
    visited[start] = 1;
    queue[++rear] = start;
    printf("BFS Traversal: ");
    while (front != rear)
    {
        u = queue[++front];
        printf("%d ", u);
        for (i = 0; i < vertices; i++)
        {
            if (adj[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}
void DFS(int u)
{
    int i;
    visited[u] = 1;
    printf("%d ", u);
    for (i = 0; i < vertices; i++)
    {
        if (adj[u][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int start, i;
    createGraph();
    displayGraph();
    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    BFS(start);
    for (i = 0; i < vertices; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");
    return 0;
}