#include<bits/stdc++.h>
using namespace std;
long long derangement(long long n);
int main()
{
    long long n,v;
    scanf("%lld",&n);
    v=derangement(n);
    printf("%lld\n",v);
    return 0;
}
long long derangement(long long n)
{
    long long ans;
    if(n==2)
    {
        return 1;
    }
    else if(n<2)
    {
        return 0;
    }
    else
    {
        n--;
        ans=((n)*derangement(n-1))+((n)*derangement(n));
        return ans;
    }
}
