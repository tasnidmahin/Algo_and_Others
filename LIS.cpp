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
ll dp[100005];
ll lis2()
{
    ll rt=1;
    for(int i=1;i<n;i++)
    {
        ll a=1;
        for(int j=0;j<i;j++)
        {
            if(ara[i]>ara[j])
            {
                a=max(a,dp[j]+1);
            }
        }
        dp[i]=a;
        rt=max(rt,a);
    }
    return rt;
}
int main()
{
    int t,test;
    ll a,b,c;
    sl(n);
    lop0(i,n)
    {
        sl(ara[i]);
        dp[i]=1;
    }
    a=lis2();
    pl(a);
    /*lop0(i,n)
    {
        cout << dp[i] << "  ";
    }*/
    return 0;
}

