void FW()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]>(dis[i][k]+dis[k][j]))
                {
                    dis[i][j]=(dis[i][k]+dis[k][j]);
                }
            }
        }
    }
}
