#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  mem(ara,vl)     memset(ara,vl,sizeof(ara))
#define  lop1(i,n)       for(int i=1;i<=n;i++)
#define  lop0(i,n)       for(int i=0;i<n;i++)
#define  sf(n)           scanf("%d",&n)
#define  sff(a,b)        scanf("%d %d",&a,&b)
#define  sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define  sl(n)           scanf("%lld",&n)
#define  sll(a,b)        scanf("%lld %lld",&a,&b)
#define  slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define  pf(n)           printf("%d\n",n)
#define  Mod             10000007
#define  inf             INT_MAX
#define  pb              push_back
#define  PI              acos(-1.00)
#define  eps             1e-9
int ara[10000000];
int mark[10000000];
int prm[10000000];
int pwr[10000000];
int sieve(int nm)
{
    int num,n,i=0,lmt;
    lmt=sqrt(nm+1);
    for(num=2;num<=lmt;num++)
    {
        if(mark[num]==0)
        {
            prm[i]=num;
            i++;
            for(n=num+num;n<=nm;n+=num)
            {
                mark[n]=1;
            }
        }
    }
    return i;
}
int  pfact(int num)
{
    int lp=sieve(num);
    int i,j=0,n=num,v,f=0;
    for(i=0;i<lp;i++)
    {
        int cnt=0;
        v=0;
        while(n%prm[i]==0)
        {
            v=1;
            n=n/prm[i];
            if(n==1)
            {
                printf("%d\n",prm[i]);
            }
            else
            {
                printf("%d x ",prm[i]);
            }
            cnt++;
        }
        if(v==1)
        {
            f=1;
            ara[j]=prm[i];
            pwr[j++]=cnt;
        }
    }
    return j;
}
int main()
{
    int i,num,ans,nod=1;
    double sod=1,dv,up,dwn,totnt=1;
    sf(num);
    if(num>1)
    {
        int lp=pfact(num);
    }
    else
    {
        printf("Not Prime\n");
    }
    return 0;
}

