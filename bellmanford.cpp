#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,cost;
}edge[100];

int n,m;

int neg[100],dis[100] ;

void bellmanford()
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dis[edge[j].v] = min(dis[edge[j].v], dis[edge[j].u]+edge[j].cost);
        }
    }

    for(int j=1;j<=m;j++)
    {
        if(dis[edge[j].v] > dis[edge[j].u]+edge[j].cost)
        {
            neg[edge[j].v] = 1;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        dis[i] = 1e9;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i].u = a;
        edge[i].v = b;
        edge[i].cost = c;
    }
    dis[edge[1].u] = 0;
    bellmanford();
    for(int i=1;i<=n;i++)
    {
        cout << neg[i] << '\n';
    }
    return 0;
}

