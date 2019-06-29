#include<bits/stdc++.h>
using namespace std;

struct work
{
    int st,et;
}ara[100];

bool cmp(work a, work b)
{
    if(a.et<b.et) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> ara[i].st >> ara[i].et;
    }
    sort(ara,ara+n,cmp);
    int ans = 0, prev = -1;
    for(int i=0;i<n;i++)
    {
        if(ara[i].st>prev)
        {
            ans++;
            prev = ara[i].et;
        }
    }
    cout << ans << '\n';
    return 0;
}


