#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int ln,rn,cost;
}ed[10000000];
bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
int par[10000000];
int egnm,n;
void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        par[i]=i;
    }
}
int findr(int r)
{
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        return par[r]=findr(par[r]);
    }
}
int kruskal()
{
    int i,mst=0;
    sort(ed,ed+egnm,cmp);
    init(n);
    for(i=0;i<egnm;i++)
    {
        int a=ed[i].ln;
        int b=ed[i].rn;
        int u=findr(a);
        int v=findr(b);
        if(u!=v)
        {
            par[u]=v;
            mst+=ed[i].cost;
        }
    }
    return mst;
}
int main()
{
    int i,ans;
    scanf("%d %d",&n,&egnm);
    for(i=0;i<egnm;i++)
    {
        scanf("%d %d %d",&ed[i].ln,&ed[i].rn,&ed[i].cost);
    }
    ans=kruskal();
    printf("%d\n",ans);
    return 0;
}
