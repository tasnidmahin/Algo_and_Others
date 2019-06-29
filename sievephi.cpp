#include<bits/stdc++.h>
using namespace std;
int mark[10000000];
int ara[10000000];
void sievephi(int n);
int main()
{
    int i,j,k,l,n,t,df,v,sum;
    scanf("%d",&n);
    sievephi(n);
    for(i=1;i<=n;i++)
    {
        printf("%d : %d\n",i,ara[i]);
    }
    return 0;
}
void sievephi(int n)
{
    int i,j,k,l;
    for(i=1;i<=n;i++)
    {
        ara[i]=i;
    }
    mark[1]=1;
    for(i=2;i<=n;i++)
    {
        if(mark[i]==0)
        {
            ara[i]-=1;
            for(j=i+i;j<=n;j+=i)
            {
                mark[j]=1;
                ara[j]=(ara[j]/i)*(i-1);
            }
        }
    }
}
