#include<bits/stdc++.h>
using namespace std;

struct prdct
{
    double cost,wgt,pc;
}ara[100];

double taken[100];

bool cmp(prdct a, prdct b)
{
    return a.pc>b.pc;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> ara[i].cost >> ara[i].wgt;
        ara[i].pc = (ara[i].cost/ara[i].wgt);
    }
    sort(ara,ara+n,cmp);
    double cap;
    cin >> cap;
    int i=0;
    for(;i<n;i++)
    {
        if(ara[i].wgt>cap) break;
        cap-=ara[i].wgt;
        taken[i] = 1;
    }
    if(i<n)
    {
        taken[i] = cap/ara[i].wgt;
    }
    double profit = 0;
    for(int i=0;i<n;i++)
    {
        profit+=(ara[i].cost*taken[i]);
    }
    cout << profit << '\n';
    return 0;
}

