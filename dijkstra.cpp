//bidirectional
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int vis[1000006];
vector<int>adj[1000006];
vector<int>cost[1000006];
struct point
{
    int node,dis;
};
bool operator <(point a,point b)
{
    return a.dis>b.dis;
}
int dijkstra(int source,int destination)
{
    for(int i=0;i<1000000;i++)
    {
        vis[i]=inf;
    }
    point u,v;
    priority_queue<point>q;
    u.node=source;
    u.dis=0;
    vis[source]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        for(int i=0;i<adj[u.node].size();i++)
        {
            v.node=adj[u.node][i];
            if(vis[v.node]>vis[u.node]+cost[u.node][i])
            {
                vis[v.node]=vis[u.node]+cost[u.node][i];
                v.dis=vis[v.node];
                q.push(v);
            }
        }
    }
    return vis[destination];
}
int main()
{
    int n,edge;
    scanf("%d %d",&n,&edge);
    for(int i=0;i<1000000;i++)
    {
        adj[i].clear();
        cost[i].clear();
    }
    for(int i=0;i<edge;i++)
    {
        int fn,sn,c;
        scanf("%d %d %d",&fn,&sn,&c);
        adj[fn].push_back(sn);
        adj[sn].push_back(fn);
        cost[fn].push_back(c);
        cost[sn].push_back(c);
    }
    int src,des;
    scanf("%d %d",&src,&des);
    int ans=dijkstra(src,des);
    printf("%d",ans);
    return 0;
}
