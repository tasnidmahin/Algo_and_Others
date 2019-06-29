//bi directional
#include<bits/stdc++.h>
using namespace std;
int vis[1000000];
vector<int>adj[1000000];
void DFS(int sn)
{
    vis[sn]=1;
    int i,j;
    for(i=0;i<adj[sn].size();i++)
    {
        if(vis[adj[sn][i]]!=1)
        {
            DFS(adj[sn][i]);
        }
    }
    vis[sn]=2;
}
int main()
{
    int i,j,n,ed,f,s,sn,ds;
    scanf("%d %d",&n,&ed);    //node number & edge number
    for(i=0;i<ed;i++)
    {
        scanf("%d %d",&f,&s);
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    scanf("%d",&sn);
    DFS(sn);
    for(i=1;i<=n;i++)
    {
        cout << vis[i] << '\n';
    }
    return 0;
}
