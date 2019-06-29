#include<stdio.h>
#include<string.h>
#include<math.h>
int ara[1000000];
int ara1[1000000];
void m_sort(int a,int b);
void m_merge(int a,int b);
int main()
{
    int i,n,f,l;
    printf("Input array size\n");
    scanf("%d",&n);
    printf("Input numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    printf("Input 1st and last index for sort\n");
    scanf("%d %d",&f,&l);
    m_sort(f,l);
    for(i=f;i<=l;i++)
    {
        printf("%d ",ara[i]);
    }
    return 0;
}
void m_sort(int a,int b)
{
    if(a==b)
    {
        return;
    }
    else
    {
        m_sort(a,(a+b)/2),m_sort(((a+b)/2)+1,b);
        m_merge(a,b);
    }
}
void m_merge(int a,int b)
{
    int i,j,k,h,s;
    h=(a+b)/2;
    s=((a+b)/2)+1;
    for(i=a,j=s,k=a;k<=b;k++)
    {
        if(i>h)
        {
            ara1[k]=ara[j];
            j++;
        }
        else if(j>b)
        {
            ara1[k]=ara[i];
            i++;
        }
        else
        {
            if(ara[i]<ara[j])
            {
                ara1[k]=ara[i];
                i++;
            }
            else
            {
                ara1[k]=ara[j];
                j++;
            }
        }
    }
    for(i=a;i<=b;i++)
    {
        ara[i]=ara1[i];
    }
}
