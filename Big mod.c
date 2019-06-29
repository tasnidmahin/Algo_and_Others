#include<stdio.h>
#include<string.h>
#include<math.h>
long long big_mod(long long a,long long b,long long c);
int main()
{
    long long i,j,ans,a,b,c,n,t,df,v;
    printf("Input number,power,mod\n");
    scanf("%lld %lld %lld",&a,&b,&c);
    ans=big_mod(a,b,c);
    printf("%lld\n",ans);
    return 0;
}
long long big_mod(long long a,long long b,long long c)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        long long d=big_mod(a,b/2,c);
        return ((d*d)%c);
    }
    else
    {
        return (((a%c)*big_mod(a,b-1,c))%c);
    }
}
