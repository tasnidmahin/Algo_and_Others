Segmnet Tree(Lazy):
int toggle[30000007];
int sum[30000007];
int num[30000007];
void build(int in,int L, int R)
{
    sum[in]=0;
    if(L==R)
    {
        sum[in]=num[L];
        return;
    }
    int mid=(L+R)/2;
    build(in*2, L, mid);
    build((in*2)+1, mid+1, R);
    sum[in] = sum[in*2]+ sum[(in*2)+1];
    return;
}
void update(int in, int L, int R, int l, int r)
{
    if(r<L || l>R)
        return;
    if(l<=L && R<=r)
    {
        toggle[in]^=1;
        return;
    }
    int mid=(L+R)/2;
    update(in*2, L, mid, l, r);
    update((in*2)+1, mid+1, R, l, r);
}
int query(int in, int L, int R, int pos)
{
    if(pos<L || pos>R)
        return 0;
    if(L<=pos && pos<=R)
        return toggle[in];
    int mid=(L+R)/2;
    if(pos<=mid)
        return query(in*2, L, mid, pos)^toggle[in];
    else
        return query((in*2)+1, mid+1, R, pos)^toggle[in];
}
