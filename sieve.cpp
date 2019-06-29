void sieve(int nm)
{
    int num,n,lmt;
    ara[0]=ara[1]=1;
    lmt=sqrt(nm+1);
    for(num=2;num<=lmt;num++)
    {
        if(ara[num]==0)
        {
            for(n=num+num;n<=nm;n+=num)
            {
                ara[n]=1;
            }
        }
    }
}
