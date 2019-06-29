#include<bits/stdc++.h>
using namespace std;

int wgh[10000000];
int cost[10000000];
int dp[10000][10000];
int n,cap;
int call(int i,int w)
{
    if(dp[i][w]!=-1)
    {
        return dp[i][w];
    }
    if(i>=n)
    {
        return 0;
    }
    int prft1,prft2;
    if(w+wgh[i]<=cap)
    {
        prft1=cost[i]+call(i+1,w+wgh[i]);
    }
    else
    {
        prft1=0;
    }
    prft2=call(i+1,w);
    return dp[i][w]=max(prft1,prft2);
}
int main()
{
    int i,j,k,l,ln,t,test,df,v,sum;
    memset(dp,-1,sizeof(dp));
    cin >> n >> cap;
    for(int i=0;i<n;i++)
    {
        cin >> wgh[i] >> cost[i];
    }
    int ans=call(0,0);
    printf("%d\n",ans);
    return 0;
}

