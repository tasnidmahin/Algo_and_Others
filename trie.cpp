string s;
int node[MAX_NODE][26]; //assuming words will be consisted only small letters['a' - 'z']

int root,nnode;
int cnWord[MAX_NODE];

void initialize()
{
    root = 0;
    nnode = 0;
    lop0(i,26)
    {
        node[root][i] = -1;
    }
}

void insrt()
{
    sf(s);
    int l = s.size();
    int now = root;
    lop0(i,l)
    {
        if(node[now][s[i] - 'a'] == -1)
        {
            node[now][s[i] - 'a'] = ++nnode;
            lop0(j,26)
            {
                node[nnode][j] = -1;
            }
        }
        now = node[now][s[i] - 'a'];
        cnWord[now]++;
    }
}

int query()
{
    int ret = 0;
    sf(s);
    int l = s.size();
    int now = root;
    lop0(i,l)
    {
        if(node[now][s[i] - 'a'] == -1)
        {
            return 0;
        }
        else
        {
            now = node[now][s[i] - 'a'];
            ret = cnWord[now];
        }
    }
    return ret;
}

