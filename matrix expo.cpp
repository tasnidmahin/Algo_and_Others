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
#define   pl(n)           printf("%I64d\n",n)
#define   Mod             10000007
#define   inf             INT_MAX
#define   pb              push_back
#define   PI              acos(-1.00)
#define   eps             1e-9
#define   MP(x,y)         make_pair(x,y)
ll pw;
ll mat_exp()
{
    ll out[2][2],fst[2][1]={{1},{0}},tmp[2][2]={{1,0},{0,1}},a[2][2]={{1,1},{1,0}};
    while(pw!=0)
    {
        if(pw%2==1)
        {
            mem(out,0);
            lop0(i,2)
            {
                lop0(j,2)
                {
                    lop0(k,2)
                    {
                        out[i][j]=((out[i][j]+((tmp[i][k]*a[k][j])+Mod)%Mod)+Mod)%Mod;
                    }
                }
            }
            lop0(i,2)
            {
                lop0(j,2)
                {
                    tmp[i][j]=out[i][j];
                }
            }
            pw--;
        }
        else
        {
            mem(out,0);
            lop0(i,2)
            {
                lop0(j,2)
                {
                    lop0(k,2)
                    {
                        out[i][j]=((out[i][j]+((a[i][k]*a[k][j])+Mod)%Mod)+Mod)%Mod;
                    }
                }
            }
            lop0(i,2)
            {
                lop0(j,2)
                {
                    a[i][j]=out[i][j];
                }
            }
            pw/=2;
        }
    }
    mem(out,0);
    lop0(i,2)
    {
        lop0(j,1)
        {
            lop0(k,2)
            {
                out[i][j]=((out[i][j]+((tmp[i][k]*fst[k][j])+Mod)%Mod)+Mod)%Mod;
            }
        }
    }
    return out[0][0];
}
int main()
{
    int t,test;
    ll aa,b,c,n;
    sl(pw);
    aa=mat_exp();
    pl(aa);
    return 0;
}
