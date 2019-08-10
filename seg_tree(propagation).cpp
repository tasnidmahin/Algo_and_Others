//Segment Tree(Propagation):
int toggle[30000007];
int on[30000007];
void build(int in,int L, int R)
{
    on[in]=0;
    if(L==R)
    {
        sum[in]=num[L];
        return;
    }
    int mid=(L+R)/2;
    build(in*2, L, mid);
    build((in*2)+1, mid+1, R);
    on[in] = on[in*2]+ on[(in*2)+1];
    return;
}
void propagate(int in, int L, int R)
{
    int mid = (L+R)/2;
    int left_in = in*2, left_L = L, left_R = mid;
    int right_in = (in*2)+1, right_L = mid+1, right_R = R;
    toggle[in]=0;
    toggle[left_in]^=1;
    toggle[right_in]^=1;
    on[left_in] = left_R - left_L + 1 - on[left_in];
    on[right_in] = right_R - right_L + 1 - on[right_in];
}
void update(int in, int L, int R, int l, int r)
{
    if(r<L || l>R)
        return;
    if(l<=L && R<=r)
    {
        toggle[in]^=1;
        on[in] = R - L + 1 - on[in];
        return;
    }

    if(toggle[in])
        propagate(in,L,R);
    int mid = (L+R)/2;
    update(in*2, L, mid, l, r);
    update((in*2)+1, mid+1, R, l, r);

    on[in] = on[in*2] + on[(in*2)+1];
}
int query(int in, int L, int R, int l, int r)
{
    if(r<L || l>R)
        return 0;
    if(l<=L && R<=r)
        return on[in];
    if(toggle[in])
        propagate(in,L,R);
    int mid=(L+R)/2;
    int x = query(in*2, L, mid, l, r);
    int y = query((in*2)+1, mid+1, R, l, r);

    return x+y;
}
