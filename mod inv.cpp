#include<bits/stdc++.h>
using namespace std;
void sieve(long long nm);
long long big_mod(long long a,long long b,long long c);
void sievephi(long long n);
int ara[10000000];
int mark[10000000];
int ara2[10000000];
long long ans;
int mod_inv(long long a,long long m)
{
    int v=1;
    if(a==0 || m==0)
    {
        v=2;
        return v;
    }
    long long i;
    sieve(m);
    if(ara[m]==0)
    {
        ans=big_mod(a,m-2,m);
        v=1;
        return v;
    }
    else
    {
        if(a<m)
        {
            for(i=2;i<=a;i++)
            {
                if(a%i==0 && m%i==0)
                {
                    v=0;
                    return v;
                }
            }
        }
        else
        {
            for(i=2;i<=m;i++)
            {
                if(a%i==0 && m%i==0)
                {
                    v=0;
                    return v;
                }
            }
        }
        if(v==1)
        {
            sievephi(m);
            ans=big_mod(a,ara2[m]-1,m);
            return v;
        }
    }
}
int main()
{
    int v;
    long long a,m;
    scanf("%lld %lld",&a,&m);
    v=mod_inv(a,m);
    if(v==1)
    {
        printf("%lld\n",ans);
    }
    else if(v==0)
    {
        printf("It is impossible to determine modular inverse for these numbers\n");
    }
    else
    {
        printf("Invalid Input\n");
    }
    return 0;
}
void sieve(long long nm)
{
    long long num,n,lmt;
    lmt=sqrt(nm+1);
    for(num=2;num<=lmt;num++)
    {
        if(ara[num]==0)
        {
            for(n=num+num;n<=nm;n+=num)
            {
                ara[n]=1;
            }
        }
    }
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
void sievephi(long long n)
{
    long long i,j,k,l;
    for(i=1;i<=n;i++)
    {
        ara2[i]=i;
    }
    mark[1]=1;
    for(i=2;i<=n;i++)
    {
        if(mark[i]==0)
        {
            ara2[i]-=1;
            for(j=i+i;j<=n;j+=i)
            {
                mark[j]=1;
                ara2[j]=(ara2[j]/i)*(i-1);
            }
        }
    }
}
