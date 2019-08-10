#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(ll i = 1;i<=n;i++)
#define rep0(i,n) for(ll i = 0;i<n;i++)
#define reps(i,a,n) for(ll i = a;i<=n;i++)
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define pf(n) printf("%lld\n",n)
#define pfs(s) printf("%s\n",s)
#define bug printf("BUG\n")
#define pfstr(s) printf("%s\n",s.c_str())
#define cs(i,n) printf("Case %lld: %lld\n",i,n)
#define clr(dp,v) memset(dp,v,sizeof dp)
#define pb push_back
#define mpr make_pair
#define PLL pair<ll,ll>
#define ff first
#define ss second
#define mx 200002
#define mod 10000000
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll a[mx];
vector<ll>tree[4*mx];
ll n;

void build(ll node,ll L,ll R)
{
  if(L==R)
  {
    tree[node].push_back(a[L]);
    return;
  }

  ll left = 2*node;
  ll right = 2*node+1;

  ll mid = (L+R)/2;
  build(left,L,mid);
  build(right,mid+1,R);
  merge(all(tree[left]),all(tree[right]),back_inserter(tree[node]));
}

ll query(ll node,ll L,ll R,ll i,ll j,ll val)
{
  if(i>R||L>j) return 0;
  if(i<=L&&R<=j){
    return lower_bound(all(tree[node]),val)-tree[node].begin();
  }
  ll mid = (L+R)/2;
  ll left = 2*node;
  ll right = 2*node+1;
  return query(left,L,mid,i,j,val)+query(right,mid+1,R,i,j,val);
}


int main()
{
sf(n);

rep(i,n)
{
  sf(a[i]);
}

build(1,1,n);


return 0;
}
