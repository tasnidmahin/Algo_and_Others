#include<bits/stdc++.h>
using namespace std;
double num_dig_fact(long long num);
int main()
{
    long long i,n,v;
    double answer;
    scanf("%lld",&n);
    answer=num_dig_fact(n);
    printf("%.0lf\n",answer);
    return 0;
}
double num_dig_fact(long long num)
{
    long long i;
    double ans=0.0;
    for(i=1;i<=num;i++)
    {
        ans+=log10(i);
    }
    ans=floor(ans);
    ans+=1;
    return ans;
}
