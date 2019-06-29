#include<stdio.h>
int gcd(int boro,int soto);
int main()
{
    int num1,num2,result;
    printf("Input numbers\n");
    scanf("%d %d",&num1,&num2);
    result=gcd(num1,num2);
    printf("GCD of %d and %d is : %d",num1,num2,result);
    return 0;
}
int gcd(int boro,int soto)
{
    int a;
    /*if(soto==0)
    {
        return boro;
    }
    else if(boro==0)
    {
        return soto;
    }*/
    while(1)
    {
        a=boro%soto;
        if(a==0)
        {
            return soto;
        }
        else
        {
            boro=soto;
            soto=a;
        }
    }
}
