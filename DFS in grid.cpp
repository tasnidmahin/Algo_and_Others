#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int vis[10000][10000];
int cost[10000][10000];
char ara[10000][10000];
int clm,rw;
void DFS2(int sx,int sy)
{
    int i,j;
    vis[sy][sx]=1;
    for(i=0;i<4;i++)
    {
        int ux=sx+dx[i];
        int uy=sy+dy[i];
        if(ux>=0 && uy>=0 && ux<clm && uy<rw)
        {
            if(vis[uy][ux]!=1)
            {
                DFS2(ux,uy);
            }
        }
    }
}
int main()
{
    int i,sx,sy;
    scanf("%d %d",&clm,&rw);    //length and width of a grid
    for(i=0;i<rw;i++)
    {
        scanf("%s",&ara[i]);
    }
    scanf("%d %d",&sx,&sy);
    memset(vis,0,sizeof(vis));
    DFS2(sx,sy);
    printf("%d\n",vis[3][4]);
    return 0;
}
