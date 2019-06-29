int num[30000007];
int sum[40000007];

void build(int in, int  L,  int R)
{
    sum[in] = 0;
    if(L == R)
    {
        sum[in] = num[L];
        return;
    }
    int mid = (L+R)/2;
    build(in*2, L, mid);
    build((in*2)+1, mid+1, R);
    sum[in] = sum[in*2]+ sum[(in*2)+1];
    return;
}
void  update(int in,int L,int  R,int pos, int u)
{
    if(L == R)
    {
        sum[in] += u;
        return;
    }
    int mid = L+R)/2;
    if(pos<= mid)
        update(in*2, L, mid, pos, u);
    else
        update((in*2)+1, mid+1, R,      pos, u);
    sum[in]  =  sum[in*2] + sum[(in*2)+1];
}
int query(int in, int L, int R, int l, int r)
{
    if(r<L || l>R)
        return 0;
    if(l<= L && R<= r)
        return sum[in];
    int mid = (L+R)/2;
    int x = query(in*2, L, mid, l, r);
    int y = query((in*2)+1, mid+1, R, l, r);
    return x+y;
}
