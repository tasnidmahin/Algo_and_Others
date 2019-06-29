#include<stdio.h>
#include<math.h>
int size(char str[]);
int transf(char num[300]);
int main()
{
    int ans;
    char num[300]={};
    gets(num);
    ans=transf(num);
    printf("Decimal number:%d\n",ans);
    return 0;
}
int size(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
int transf(char num[300])
{
    int i,dec=0;
    int len=size(num);
    int pos=len-1;
    for(i=0;i<len;i++)
    {
        dec+=(num[i]-'0')*pow(2,pos);
        pos--;
    }
    return dec;
}
