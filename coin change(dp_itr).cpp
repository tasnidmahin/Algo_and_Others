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
ll n,make;
//ll dp[105][100005];
ll dp[100005];
int coin[105];
/*void call()
{
    for(int j=0;j<make+1;j++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-coin[i]>=0)
            {
                dp[i][j]+=dp[i][j-coin[i]];
            }
        }
    }
}*/
void call2()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<make+1;j++)
        {
        //for(int i=1;i<=n;i++)
        //{
            if(j-coin[i]>=0)
            {
                dp[j]+=dp[j-coin[i]];
            }
        //}
        }
    }
}
int main()
{
    int t,test;
    ll a,b,c;
    mem(dp,0);
    //dp[0][0]=1;
    dp[0]=1;
    sll(n,make);
    lop1(i,n)
    {
        sf(coin[i]);
    }
    //call();
    call2();
    //pl(dp[n][make]);
    //pl(dp[make]);
    lop0(i,make+1)
    {
        pl(dp[i]);
    }
    cout << "Call3         ....\n";
    mem(dp,0);
    //dp[0][0]=1;
    dp[0]=1;
    call3();
    lop0(i,make+1)
    {
        pl(dp[i]);
    }
    return 0;
}

