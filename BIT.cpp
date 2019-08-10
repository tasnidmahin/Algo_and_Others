// 1 indexed
ll read(ll idx)
{
    ll sum = 0;

    while(idx>0)
    {
        sum += tre[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(ll idx, ll val)
{
    while(idx<=n)
    {
        tre[idx] += val;
        idx += (idx & -idx);
    }
}
