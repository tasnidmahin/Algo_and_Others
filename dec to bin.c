#include<stdio.h>
#include<math.h>
int ara[100000];
void transf(int num);
int main()
{
    int ans,num;
    scanf("%d",&num);
    transf(num);
    return 0;
}
void transf(int num)
{
    int i,pos=0,l,sum=0;
    for(i=0;;i++)
    {
        if(pow(2,i)>num)
        {
            break;
        }
        pos=i;
    }
    l=pos+1;
    sum=pow(2,pos);
    ara[0]=1;
    pos--;
    for(i=1;i<l;i++,pos--)
    {
        if(sum+pow(2,pos)>num)
        {
            ara[i]=0;
        }
        else
        {
            sum+=pow(2,pos);
            ara[i]=1;
        }
    }
    for(i=0;i<l;i++)
    {
        printf("%d",ara[i]);
    }
    printf("\n");
}
