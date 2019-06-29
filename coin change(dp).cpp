#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define   mem(ara,vl)     memset(ara,vl,sizeof(ara))
#define   lop1(i,n)       for(int i=1;i<=n;i++)
#define   lop0(i,n)       for(int i=0;i<n;i++)
#define   lop(i,a,n)      for(int i=a;i<n;i++)
#define   sf(n)           scanf("%d",&n)
#define   sff(a,b)        scanf("%d %d",&a,&b)
#define   sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define   sl(n)           scanf("%lld",&n)
#define   sll(a,b)        scanf("%lld %lld",&a,&b)
#define   slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define   pf(n)           printf("%d\n",n)
#define   pl(n)           printf("%I64d\n",n)
#define   Mod             10000007
#define   inf             INT_MAX
#define   pb              push_back
#define   PI              acos(-1.00)
#define   eps             1e-9
#define   MP(x,y)         make_pair(x,y)
ll make,n;
int coin[100005];
//ll dp[10004][10004];
ll dp[10004];
map<int ,int> mp;
/*int call1(int i,int amount)
{
    if(i>=100005)
    {
        if(amount==make)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][amount]!=-1)
    {
        return dp[i][amount];
    }
    int ret1=0,ret2=0;
    if(coin[i]+amount<=make)
    {
        ret1=call1(i,amount+coin[i]);
    }
    ret2=call1(i+1,amount);
    return dp[i][amount]=ret1 | ret2;
}
ll call(ll i,ll amount)
{
    if(i>=n)
    {
        if(amount==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][amount]!=-1)
    {
        return dp[i][amount];
    }
    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0)
    {
        ret1=call(i,amount-coin[i]);
    }
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1 + ret2;
}
ll caller(ll i,ll amount)
{
    if(i==0)
    {
        if(amount==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][amount]!=-1)
    {
        return dp[i][amount];
    }
    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0)
    {
        ret1=caller(i,amount-coin[i]);
    }
    ret2=caller(i-1,amount);
    return dp[i][amount]=ret1 + ret2;
}*/
ll callers(ll i,ll amount)
{
    if(i==0)
    {
        if(amount==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[amount]!=-1)
    {
        return dp[amount];
    }
    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0)
    {
        ret1=callers(i,amount-coin[i]);
    }
    ret2=callers(i-1,amount);
    return dp[amount]=ret1 + ret2;
}
int main()
{
    int t,test;
    ll a,b,c;
    mem(dp,-1);
    sll(n,make);
    lop1(i,n)
    {
        sf(coin[i]);
    }
    a=callers(n,make);
    pl(a);
    /*lop1(i,n)
    {
        lop0(j,make+1)
        {
            cout << i << "  " << j << "  " << dp[i][j] << '\n';
        }
    }*/
    return 0;
}

