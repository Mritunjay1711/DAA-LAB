#include<stdio.h>
#include<stdlib.h>
#define V 6
#define E 9

typedef struct DSU
{
    int parent[V];
    int rank[V];
}DSU;

typedef struct edgeList
{
    int x, y, w;
}edgeList;

int find(DSU *d, int i)
{
    if(d->parent[i] == -1)
        return i;
    return d->parent[i] = find(d, d->parent[i]);
}

void unite(DSU *d, int x, int y)
{
    int s1 = find(d, x);
    int s2 = find(d, y);

    if(s1 != s2)
    {
        if(d->rank[s1] > d->rank[s2])
        {
            d->parent[s2] = s1;
            d->rank[s1] += d->rank[s2];
        }
        else
        {
            d->parent[s1] = s2;
            d->rank[s2] += d->rank[s1];
        }
    }
}


int kruskal(edgeList graph[E])
{
    DSU d;
    for(int i = 0; i < V; i++)
    {
        d.parent[i] = -1;
        d.rank[i] = 1;
    }

    for(int i = 0; i < E - 1; i++)
    {
        for(int j = 0; j < E - i - 1; j++)
        {
            if(graph[j].w > graph[j+1].w)
            {
                edgeList temp = graph[j];
                graph[j] = graph[j+1];
                graph[j+1] = temp;
            }
        }
    }

    int cost = 0;
    printf("Edge   Weight\n");
    for(int i = 0; i < E; i++)
    {
        if(find(&d, graph[i].x) != find(&d, graph[i].y))
        {
            unite(&d, graph[i].x, graph[i].y);
            cost += graph[i].w;
            printf("%d-%d\t%d\n", graph[i].x, graph[i].y, graph[i].w);
        }
    }
    return cost;
}

int main()
{
    edgeList graph[E] = {{0, 1, 5},
                        {0, 4, 3},
                        {0, 2, 2},
                        {1, 4, 2},
                        {2, 4, 6},
                        {2, 5, 1},
                        {2, 3, 7},
                        {4, 5, 3},
                        {3, 5, 4}};
    
    printf("Cost: %d\n", kruskal(graph));
    return 0;
}