#include<bits/stdc++.h>
using namespace std;
int ara[20000][20000];
int comb1(int n,int r)
{
    if(n==r)
    {
        return ara[n][r]=1;
    }
    else if(r==1)
    {
        return ara[n][r]=n;
    }
    else if(ara[n][r]!=-1)
    {
        return ara[n][r];
    }
    else
    {
        return ara[n][r]=comb1(n-1,r)+comb1(n-1,r-1);
    }
}
int main()
{
    int ans,i,n,r;
    scanf("%d %d",&n,&r);
    for(i=1;i<=n;i++)
    {
        int j;
        for(j=1;j<=n;j++)
        {
            ara[i][j]=-1;
        }
    }
    ans=comb1(n,r);
    printf("%d\n",ans);
    return 0;
}
