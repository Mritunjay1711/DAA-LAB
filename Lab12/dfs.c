#include<stdio.h>
#include<stdlib.h>
#define V 7

void dfs(int graph[V][V], int *visited, int ind)
{
    if(visited[ind])
        return;
    visited[ind] = 1;
    printf("%d ", ind);
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0 && graph[ind][i] == 1)
        {
            dfs(graph, visited, i);
        }
    }
    
}

int main()
{
    int graph[V][V] =  {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0}};


    int *visited = (int*)calloc(V, sizeof(int));
    dfs(graph, visited, 5);
    return 0;
}