int ara[505][505];

int sum[4000005];

void build(int node,int a,int b,int c,int d)
{
    if((a>b)||(c>d))
    {
        return;
    }
    if((a==b)&&(c==d))
    {
        sum[node]=ara[a][c];
        return;
    }
    build(node*4-2,a,(a+b)/2,c,(c+d)/2);
    build(node*4-1,(a+b)/2+1,b,c,(c+d)/2);
    build(node*4+0,a,(a+b)/2,(c+d)/2+1,d);
    build(node*4+1,(a+b)/2+1,b,(c+d)/2+1,d);
    sum[node]=max4(sum[node*4-2],sum[node*4-1],sum[node*4+0],sum[node*4+1]);
}
int query(int node,int a,int b,int c,int d,int e,int f,int g,int h)
{
    if((a>f)||(b<e)||(c>h)||(d<g))
    {
        return 0;
    }
    if((a>=e)&&(b<=f)&&(c>=g)&&(d<=h))
    {
        return sum[node];
    }
    return max4(query(node*4-2,a,(a+b)/2,c,(c+d)/2,e,f,g,h),query(node*4-1,(a+b)/2+1,b,c,(c+d)/2,e,f,g,h),query(node*4+0,a,(a+b)/2,(c+d)/2+1,d,e,f,g,h),query(node*4+1,(a+b)/2+1,b,(c+d)/2+1,d,e,f,g,h));
}

