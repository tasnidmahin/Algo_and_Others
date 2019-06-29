/*
G[][]: undirected graph
cut[v] is true if node v is an articulation point / cut-vertex
*/

vector< int > G[MAX];
int low[MAX], vis[MAX], used[MAX], cut[MAX], dfstime;

void dfs(int u, int par = -1) {
    int i, v, child = 0;
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if(v == par) continue;
        if(used[v]) low[u] = min(low[u], vis[v]);
        else {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= vis[u]) cut[u] = 1;
        }
    }
    if(par == -1) cut[u] = (child > 1);
}
