int imp = 0;
int vis[1000000];
vector<int>adj[1000000];
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
        else if(vis[adj[sn][i]]==1)
        {
            imp = 1;
        }
    }
    vis[sn]=2;
    st.push(sn);
}

int main()
{
    int n,e;
    sff(n,e);
    lop0(i,e)
    {
        int f,s;
        sff(f,s);
        adj[f].push_back(s);
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i] == 0)
            DFS(i);
    }
    while(!st.empty())
    {
        int a = st.top();
        st.pop();
        pf(a);
    }
    return 0;
}
