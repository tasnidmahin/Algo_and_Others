#include<bits/stdc++.h>
using namespace std;

int n,v=0,c=1;
int ara[100][100];

bool check(int rw, int col)
{
    /*for(int i=0;i<rw;i++)
    {
        if(ara[i][col] == 1) return false;
    }*/
    for(int i=0;i<col;i++)
    {
        if(ara[rw][i] == 1) return false;
    }
    for(int i = rw-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(ara[i][j] == 1) return false;
    }
    for(int i = rw+1,j=col-1;i<n && j>=0;i++,j--)
    {
        if(ara[i][j] == 1) return false;
    }
    return true;
}

bool nqueen(int col)
{
    if(col == n)
    {
        cout << "\n\n" << c++ << " th solution\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << ara[i][j] << " ";
            }
            cout << '\n';
        }
        v = 1;
        return true;
    };

    for(int i=0;i<n;i++)
    {
        if(check(i,col))
        {
            ara[i][col] = 1;
            bool ret = nqueen(col+1);
            ara[i][col] = 0;
        }
    }
    if(v) return true;
    return false;
}

int main()
{
    cin >> n;
    bool  ans = nqueen(0);
    if(!ans)
    {
        cout << "There is no solution\n";
    }
    return 0;
}
