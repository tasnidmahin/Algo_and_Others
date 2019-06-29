#include<stdio.h>
int array[10000000];
int powr[1000000];
int prime[1000000];
void sieve(int nm);
int prime_factorization(int num);
int main()
{
    int i,num,ans,nod=1;
    double sod=1,dv,up,dwn,totnt=1;
    printf("Input a number\n");
    scanf("%d",&num);
    ans=prime_factorization(num);
    for(i=0;i<ans;i++)
    {
        nod*=(powr[i]+1);
    }
    for(i=0;i<ans;i++)
    {
        up=pow(prime[i],powr[i]+1)-1;
        dwn=prime[i]-1;
        sod*=up/dwn;
    }
    for(i=0;i<ans;i++)
    {
        dv=1.0/prime[i];
        totnt*=(1-dv);
    }
    totnt*=num;
    printf("NOD:\t%d\nSOD:\t%.0lf\nTOTIENT:\t%.0lf\n",nod,sod,totnt);
    return 0;
}
void sieve(int nm)
{
    int num,n,lmt;
    lmt=sqrt(nm+1);
    for(num=2;num<=lmt;num++)
    {
        if(array[num]==0)
        {
            for(n=num+num;n<=nm;n+=num)
            {
                array[n]=1;
            }
        }
    }
}
int prime_factorization(int num)
{
    int i,j=0,n,v;
    sieve(num);
    if(num>1)
    {
        printf("%d = ",num);
        n=num;
        for(i=2;i<=num;i++)
        {
            if(array[i]==0)
            {
                int cnt=0;
                v=0;
                while(n%i==0)
                {
                    v=1;
                    n=n/i;
                    if(n==1)
                    {
                        printf("%d\n",i);
                    }
                    else
                    {
                        printf("%d x ",i);
                    }
                    cnt++;
                }
                if(v==1)
                {
                    prime[j]=i;
                    powr[j++]=cnt;
                }
            }
        }
    }
    else if(num==0 || num==1)
    {
        printf("%d = %d\n",num,num);
    }
    else
    {
        printf("Negative numbers are not prime numbers.\n");
    }
    return j;
}
