/*
G[][]: undirected graph
finds all the bridges in a connected graph and
adds those edges to the Bridges[] vector
*/

vector< int > G[MAX];
vector< pair< int, int > > Bridges;
int low[MAX], vis[MAX], used[MAX], dfstime;

void dfs(int u, int par) {
    int i, v;
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if(v == par) continue;
        if(used[v]) low[u] = min(low[u], vis[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > vis[u]) Bridges.push_back(make_pair(u, v));
        }
    }
}
