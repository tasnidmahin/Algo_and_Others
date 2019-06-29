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
#define   pl(n)           printf("%lld\n",n)
#define   Mod             10000007
#define   inf             INT_MAX
#define   pb              push_back
#define   PI              acos(-1.00)
#define   eps             1e-9
#define   MP(x,y)         make_pair(x,y)
ll n;
ll ara[100005];
ll dp[105][105];
ll mcm(int i,int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return dp[i][j]=0;
    ll rt=inf;
    for(int k=i;k<j;k++)
    {
        rt=min(rt,mcm(i,k)+mcm(k+1,j)+(ara[i-1]*ara[k]*ara[j]));
    }
    return dp[i][j]=rt;
}
ll mcm2()
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=i;j<n;j++)
        {
            ll rt=inf;
            for(int k=i;k<j;k++)
            {
                rt=min(rt,dp[i][k]+dp[k+1][j]+(ara[i-1]*ara[k]*ara[j]));
            }
        }
    }
}
int main()
{
    int t,test;
    ll a,b,c;
    mem(dp,-1);
    sl(n);
    lop0(i,n)
    {
        sl(ara[i]);
    }
    a=mcm(1,n-1);
    pl(a);
    mem(dp,0);
    a=mcm2();
    pl(a);
    return 0;
}

