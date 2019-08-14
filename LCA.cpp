//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 100002
ll L[10004]; //level
ll P[10004][22]; //sparse table
vector<pll>g[10004];

ll vis[10004];


void dfs(ll from,ll u,ll dep,ll dis)
{
    P[u][0]=from;
    L[u]=dep;
    vis[u] = dis;
    for(ll i=0;i<g[u].size();i++)
    {
        ll v=g[u][i].F;
        if(v==from) continue;
        dfs(u,v,dep+1,dis+g[u][i].S);
    }
}

ll lcaQ(ll N, ll p, ll q) //N=node number
{
    if (L[p] < L[q]) swap(p,q);
    for (ll i = 18; i >= 0; i--){      //lift p to the same level of q
      if (L[p] - (1 << i) >= L[q]){
          p = P[p][i];
      }
    }

    if (p == q)return p;

    for (ll i = 18; i >= 0; i--){
      if (P[p][i] != 0 && P[p][i] != P[q][i]){
          p = P[p][i], q = P[q][i];
      }
    }

    return P[p][0];
}

void lca_init(ll N)
{
      for (ll j = 1; 1 << j < N; j++) // make spars table
         for (ll i = 0; i < N; i++)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

