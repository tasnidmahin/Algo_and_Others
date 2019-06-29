int vis[1000000];
vector<int>adj[1000000];
vector<int>rev_adj[1000000];
stack<int> st;
void DFS(int sn)
{
    vis[sn]=1;
    int i,j;
    for(i=0; i<adj[sn].size(); i++)
    {
        if(vis[adj[sn][i]]==0)
        {
            DFS(adj[sn][i]);
        }
    }
    vis[sn]=2;
    st.push(sn);
}
void dfs2(int sn, int grp)
{
    vis[sn]=grp;
    int i,j;
    for(i=0; i<rev_adj[sn].size(); i++)
    {
        if(vis[rev_adj[sn][i]]==0)
        {
            dfs2(rev_adj[sn][i],grp);
        }
    }
}
int main()
{
    mem(vis,0);
    int n,e;
    sff(n,e);
    lop0(i,e)
    {
        int f,s;
        sff(f,s);
        adj[f].push_back(s);
        rev_adj[s].push_back(f);
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i] == 0)
            DFS(i);
    }
    mem(vis,0);
    int cnt = 1;
    while(!st.empty())
    {
        int a = st.top();
        st.pop();
        if(vis[a] == 0)
            dfs2(a,cnt++);
    }
    lop1(i,n)
    {
        cout << "I  " << i << "     " << vis[i] << '\n';
    }
    return 0;
}
