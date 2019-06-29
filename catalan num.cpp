#include<bits/stdc++.h>
using namespace std;
long long catalan(long long n);
long long comb(long long n,long long r);
int main()
{
    long long n,ans;
    scanf("%lld",&n);
    ans=catalan(n);
    printf("%lld\n",ans);
    return 0;
}
long long catalan(long long n)
{
    long long rt,num;
    num=2*n;
    rt=comb(num,n);
    rt=rt/(n+1);
    return rt;
}
long long comb(long long n,long long r)
{
    long long i,j=1;
    long long g=1;
    for(i=n-r+1;i<=n;i++)
    {
        g*=i;
        g/=j;
        j++;
    }
    return g;
}
