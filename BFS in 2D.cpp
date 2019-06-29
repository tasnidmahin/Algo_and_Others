//bi directional
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int vis[10000][10000];
int cost[10000][10000];
char ara[10000][10000];
int clm,rw;
void BFS2(int sx,int sy)
{
    int i,j;
    queue<int>qx,qy;
    memset(cost,0xF,sizeof(cost));
    memset(vis,0,sizeof(vis));
    cost[sy][sx]=0;
    vis[sy][sx]=1;
    qx.push(sx);
    qy.push(sy);
    while(qx.empty()!=1)
    {
        int vx=qx.front();
        int vy=qy.front();
        for(i=0;i<4;i++)
        {
            int ux=vx+dx[i];
            int uy=vy+dy[i];
            if(ux>=0 && uy>=0 && ux<clm && uy<rw)
            {
                if(vis[uy][ux]!=1)
                {
                    vis[uy][ux]=1;
                    cost[uy][ux]=cost[vy][vx]+1;
                    qx.push(ux);
                    qy.push(uy);
                }
            }
        }
        qx.pop();
        qy.pop();
    }
}
int main()
{
    int i,j,n,ed,f,s,sx,sy,dsx,dsy;
    scanf("%d %d",&clm,&rw);    //length and width of a grid
    for(i=0;i<rw;i++)
    {
        scanf("%s",&ara[i]);
    }
    scanf("%d %d",&sx,&sy);
    scanf("%d %d",&dsx,&dsy);
    BFS2(sx,sy);
    printf("Shortest Distance %d\n",cost[dsx][dsy]);
    return 0;
}
