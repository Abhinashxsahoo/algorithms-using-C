#include <stdio.h>
#include <limits.h>
#define V 6
int main()
{
    int Graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {0, 0, 3, 2, 0, 0},
        {0, 1, 0, 4, 5, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, -5, 0, 0},
        {0, 0, 0, 0, 5, 0}};
    char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char source = 'A';
    int sourceIndex = -1;
    for (int i = 0; i < V; i++)
    {
        if (vertices[i] == source)
        {
            sourceIndex = i;
            break;
        }
    }
    if (sourceIndex == -1)
    {
        printf("Source vertex not found!\n");
        return 1;
    }
    // List all the edges in the graph
    printf("Edges of the graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (Graph[i][j] && i != j)
            {
                printf("%c-%c\tWeight: %d\n", vertices[i], vertices[j], Graph[i][j]);
            }
        }
    }
    printf("\n");
    int dist[V];
    // Print the shortest path from vertex 0 to all other vertices
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[sourceIndex] = 0;
    //bellman ford Algorithm
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (Graph[j][k] && dist[j]!= INT_MAX && dist[j] + Graph[j][k] < dist[k])
                {
                    dist[k] = dist[j] + Graph[j][k];
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i]);
            }
        }
        printf("\n");
    }
    printf("\nShortest Path from source to all other vertices:\n");
    for (int i = 0; i < V; i++)
    {
        printf("%c \t\t %d\n", vertices[i], dist[i]);
    }
    return 0;
}