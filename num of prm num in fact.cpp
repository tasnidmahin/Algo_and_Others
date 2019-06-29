#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num,p,v,ans=0;
    //input of the number
    scanf("%lld",&num);
    //input of prime number
    scanf("%lld",&p);
    long long pr=p;
    v=num/p;
    while(v)
    {
        ans+=v;
        p*=pr;
        v=num/p;
    }
    printf("%lld\n",ans);
    return 0;
}

