#include<bits/stdc++.h>
using namespace std;
#define inf 9999999
int taken[10000000];
struct edge
{
    int ln,rn,cost,tree;
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
int kruskal(int flag)
{
    int i,mst=0,cn=0;
    init(n);
    for(i=0;i<egnm;i++)
    {
        if(taken[i]==0)
        {
            int a=ed[i].ln;
            int b=ed[i].rn;
            int u=findr(a);
            int v=findr(b);
            if(u!=v)
            {
                if(flag==1)
                {
                    ed[i].tree=1;
                }
                par[u]=v;
                mst+=ed[i].cost;
                cn++;
            }
        }
    }
    if(cn!=n-1)
    {
        mst=inf;
    }
    return mst;
}
int secondmst()
{
    memset(taken,0,sizeof(taken));
    sort(ed,ed+egnm,cmp);
    int v1=kruskal(1);
    int mn=inf;
    for(int i=0;i<egnm;i++)
    {
        if(ed[i].tree==1)
        {
            taken[i]=1;
            int tmp=kruskal(0);
            mn=min(mn,tmp);
            taken[i]=0;
        }
    }
    return mn;
}
int main()
{
    int i,j,l,t,test;
    memset(ed,0,sizeof(ed));
    scanf("%d %d",&n,&egnm);
    for(i=0;i<egnm;i++)
    {
        scanf("%d %d %d",&ed[i].ln,&ed[i].rn,&ed[i].cost);
    }
    int ans=secondmst();
    if(ans==inf)
    {
        printf("Case #%d : No way\n",t);
    }
    else
    {
        printf("%d\n",ans);
    }
    return 0;
}
