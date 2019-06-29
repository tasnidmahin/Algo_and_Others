#include<bits/stdc++.h>
using namespace std;
int grp[10000000];
int par[10000000];
void init(int n)
{
    int i;
    for(i=0;i<n;i++)
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
void dsu(int n,int m)
{
    init(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int u=findr(x);
        int v=findr(y);
        if(u==v)
        {
            continue;
        }
        else
        {
            par[v]=u;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    dsu(n,m);
    int nd;
    scanf("%d",&nd);
    printf("%d\n",par[nd]);
    return 0;
}
