#include<bits/stdc++.h>
using namespace std;

class DSU{
    int *parent;
    int *rank;
public:
    DSU(int V){
        parent = new int[V];
        rank = new int[V];

        for(int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
    int unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2)
        {
            if(rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int>> edgelist;
public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    int kruskal_mst()
    {
        DSU ob(V);
        sort(edgelist.begin(), edgelist.end());
        int cost = 0;
        for(auto edge: edgelist)
        {
            int w, x, y;
            w = edge[0];
            x = edge[1];
            y = edge[2];

            if(ob.find(x) != ob.find(y))
            {
                ob.unite(x, y);
                cost += w;
            }
        }
        return cost;
    }
};

int main(){
    
    return 0;
}