#include<bits/stdc++.h>

using namespace std;
int t,i,j,k,l,n,m,x,y,z,q,a[100005],tree[400005],p[50005],level[50005],sc[50005],head[50005],ind[50005],pos[50005],sz[50005],cn,chain,seg_pos[50005];
vector<int>g[50005];
map<pair<int,int>,int>mp;
struct edge
{
    int u1,v1,w;
}e[100005];
void makeset(int num)
{
    p[num]=num;
}
int findset(int r)
{
    if(p[r]==r) return r;
    else return p[r]=findset(p[r]);
}
void unionset(int a1,int a2)
{
    int u=findset(a1);
    int v=findset(a2);
    if(u!=v) p[u]=v;
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
void kruskal()
{
    sort(e,e+m,cmp);
    for(i=1;i<=n;i++) makeset(i);
    for(i=0;i<m;i++)
    {
        x=e[i].u1;
        y=e[i].v1;
        z=e[i].w;
        if(findset(x)!=findset(y))
        {
            unionset(x,y);
            g[x].push_back(y);
            g[y].push_back(x);
            mp[make_pair(x,y)]=z;
            mp[make_pair(y,x)]=z;
        }
    }
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    build(node*2,b,(b+e)/2);
    build(node*2+1,(b+e)/2+1,e);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query(int node,int b,int e,int lft,int rgt)
{
    if((e<lft)||(b>rgt)) return 0;
    if((b>=lft)&&(e<=rgt)) return tree[node];

    return max(query(node*2,b,(b+e)/2,lft,rgt),query(node*2+1,(b+e)/2+1,e,lft,rgt));
}
int dfs(int u,int par,int depth)
{
    int idx=-1;
    int mxx=0;
    int ret=1; // no of nodes in this subtree
    p[u]=par;
    level[u]=depth;
    for(int o=0;o<g[u].size();o++)
    {
        int v=g[u][o];
        if(v!=par)
        {
            int tmp=dfs(v,u,depth+1);
            if(tmp>mxx)
            {
                mxx=tmp;
                idx=v; // to select heavy node
            }
            ret+=tmp;
        }
    }
    sc[u]=idx; // my heavy node
    return ret;
}
void hld(int u,int par,int flag)
{
    if(flag==1) // for heavy chain node
    {
        a[cn++]=mp[make_pair(u,par)];//value of edge stored for seg tree
    }
    seg_pos[u]=cn;//position of node in seg tree
    a[cn++]=0; // store this node's value in array

    if(head[chain]==-1) head[chain]=u; // if it is the 1st node of this chain

    ind[u]=chain;//eta kon chain e ase
    pos[u]=sz[chain]; // chain e node er position
    sz[chain]++;
    if(sc[u]!=-1)//jodi heavy child thake
    {
        hld(sc[u],u,1);
    }
    for(int o=0;o<g[u].size();o++)//light child gular jonno
    {
        int v=g[u][o];
        if((v!=par)&&(v!=sc[u]))
        {
            chain++;
            hld(v,u,0);
        }
    }
}
void init()
{
    dfs(1,-1,0);
    chain=cn=0;
    memset(head,-1,sizeof(head));
    memset(sz,0,sizeof(sz));
    hld(1,-1,0);
    build(1,0,2*(n-1));
}
int query_hld(int u,int v)
{
    int uh=head[ind[u]]; // u je chain e ase oi chain er head
    int vh=head[ind[v]]; // v je chain e ase oi chain er head
    int ret=0;
    while(ind[u]!=ind[v]) // jodi same chain e na thake
    {
        if(level[uh]<level[vh])
        {
            swap(u,v);
            swap(uh,vh);
        }
        ret=max(ret,query(1,0,2*(n-1),seg_pos[uh],seg_pos[u]));
        ret=max(ret,mp[make_pair(uh,p[uh])]);
        u=p[uh]; // chain er baire chole gelam
        uh=head[ind[u]];
    }
    if(level[u]<level[v])
    {
        swap(u,v);
    }
    ret=max(ret,query(1,0,2*(n-1),seg_pos[v],seg_pos[u]));
    return ret;
}
int main()
{
    scanf("%d",&t);
    for(l=1;l<=t;l++)
    {
        memset(tree,0,sizeof(tree));
        mp.clear();
        for(i=0;i<50005;i++)
        {
            g[i].clear();
        }
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            e[i].u1=x;
            e[i].v1=y;
            e[i].w=z;
        }
        kruskal();
        init();
        scanf("%d",&q);
        printf("Case %d:\n",l);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",query_hld(x,y));
        }
    }
    return 0;
}
