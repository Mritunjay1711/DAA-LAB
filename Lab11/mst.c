#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 5

int minKey(int key[V], bool color[V])
{
    int min = __INT_MAX__, minIndex;
    for(int i = 0; i < V; i++)
    {
        if(color[i] == false && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }    
    }
    return minIndex;
}

void displayMST(int parent[V], int Graph[V][V])
{
    printf("Edge weight\n");
    for(int i = 1; i < V; i++)
    {
        printf("%d - %d %d\n", parent[i], i, Graph[i][parent[i]]);
    }
}

void prims(int Graph[V][V])
{
    int parent[V];
    int key[V];
    bool color[V];

    for(int i = 0; i < V; i++)
    {
        key[i] = __INT_MAX__;
        color[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;
    for(int i = 0; i < V - 1; i++)
    {
        int min = minKey(key, color);
        color[min] = true;
        for(int j = 0; j < V; j++)
        {
            if(Graph[min][j] && color[j] == false && key[j] > Graph[min][j])
            {
                key[j] = Graph[min][j]; 
                parent[j] = min;
            }
        }
    }
    displayMST(parent, Graph);
}

int main()
{
    int Graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    prims(Graph);
    return 0;
}