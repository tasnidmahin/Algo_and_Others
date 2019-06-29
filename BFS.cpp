//bi directional
#include<bits/stdc++.h>
using namespace std;
int parent[1000000];
int vis[1000000];
int cost[1000000];
vector<int>adj[1000000];
void BFS(int sn)
{
    int i;
    queue<int>q;
    memset(cost,0xF,sizeof(cost));
    memset(vis,0,sizeof(vis));
    memset(parent,0,sizeof(parent));
    cost[sn]=0;
    vis[sn]=1;
    q.push(sn);
    while(!q.empty())
    {
        int v=q.front();
        for(i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i];
            if(vis[u]!=1)
            {
                vis[u]=1;
                cost[u]=cost[v]+1;
                parent[u]=v;
                q.push(u);
            }
        }
        q.pop();
    }
}
int main()
{
    int i,j,n,ed,f,s,sn,ds;
    scanf("%d %d",&n,&ed);    //node number & edge number
    for(i=0;i<1000000;i++)
    {
        adj[i].clear();
    }
    for(i=0;i<ed;i++)
    {
        scanf("%d %d",&f,&s);
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    scanf("%d %d",&sn,&ds);
    BFS(sn);
    printf("Shortest Distance %d\n",cost[ds]);
    return 0;
}
