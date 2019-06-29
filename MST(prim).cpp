#include<bits/stdc++.h>
using namespace std;
int vis[1000000];
vector<int>adj[1000000];
vector<int>c[1000000];
struct adjacent
{
    int node,cost;
};
bool operator <(adjacent a,adjacent b)
{
    return a.cost>b.cost;
}
int prim()
{
    int mst=0;
    priority_queue<adjacent>pq;
    adjacent x;
    vis[1]=1;
    for(int i=0;i<adj[1].size();i++)
    {
        x.node=adj[1][i];
        x.cost=c[1][i];
        pq.push(x);
    }
    while(!pq.empty())
    {
        x=pq.top();
        pq.pop();
        int prsnt=x.node;
        if(vis[prsnt]==0)
        {
            vis[prsnt]=1;
            mst+=x.cost;
            for(int i=0;i<adj[prsnt].size();i++)
            {
                if(vis[adj[prsnt][i]]==0)
                {
                    x.node=adj[prsnt][i];
                    x.cost=c[prsnt][i];
                    pq.push(x);
                }
            }
        }
    }
    return mst;
}
int main()
{
    int n,eg,i,ans;
    scanf("%d %d",&n,&eg);
    for(i=0;i<eg;i++)
    {
        int a,b,cs;
        scanf("%d %d %d",&a,&b,&cs);
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a].push_back(cs);
        c[b].push_back(cs);
    }
    ans=prim();
    printf("%d\n",ans);
    return 0;
}
