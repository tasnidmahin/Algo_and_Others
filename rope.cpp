#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope> //header with rope
#include <bits/stdtr1c++.h>//for rope


using namespace __gnu_pbds;
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff
typedef long long ll;
typedef unsigned long long ull;


#define     FASTER                  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     OUT                     freopen("out.txt","w",stdout);
#define     lop1(i,n)               for(int i=1;i<=n;i++)
#define     lop0(i,n)               for(int i=0;i<n;i++)
#define     lop(i,a,n)              for(int i=a;i<=n;i++)
#define     sf1(n)                  cin >> n;
#define     sf2(a,b)                cin >> a >> b;
#define     sf3(a,b,c)              cin >> a >> b >> c;
#define     sf(n)                   scanf("%d",&n)
#define     sff(a,b)                scanf("%d %d",&a,&b)
#define     sfff(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define     sl(n)                   scanf("%lld",&n)
#define     sll(a,b)                scanf("%lld %lld",&a,&b)
#define     slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
#define     pf(n)                   cout << n << '\n';
#define     pl(n)                   printf("%I64d\n",n)
#define     ARPR(ara,s,e)           for(int i=s;i<=e;i++){  cout << ara[i]  << " "; }   cout << '\n';
#define     bug(s)                  cerr << s << '\n';
#define     bug1(s,a)               cerr << s << "      " << a << '\n';
#define     bug2(s,a,b)             cerr << s << "      " << a << "     " << b << '\n';
#define     bug3(s,a,b,c)           cerr << s << "      " << a << "     " << b << "     " << c <<'\n';
#define     bug4(s,a,b,c,d)         cerr << s << "      " << a << "     " << b << "     " << c << "     " << d <<'\n';



#define     all(v)                  v.begin(),v.end()
#define     mem(ara,vl)             memset(ara,vl,sizeof(ara))
#define     SORT(v)                 sort(v.begin(),v.end())
#define     rsort(v)                sort(v.rbegin(),v.rend())
#define     REV(v)                  reverse(v.begin(),v.end())



#define     MAX                     100
#define     max3(a,b,c)             max(a,max(b,c))
#define     max4(a,b,c,d)           max(a,max3(b,c,d))
#define     min3(a,b,c)             min(a,min(b,c))
#define     min4(a,b,c,d)           min(a,min3(b,c,d))
#define     pii                     pair<int,int>
#define     pll                     pair<ll,ll>
#define     F                       first
#define     S                       second
#define     PI                      acos(-1.00)
#define     eps                     1e-9
#define     Mod                     10000007
#define     inf                     9e18
#define     pb                      push_back
#define     MP(x,y)                 make_pair(x,y)
#define     oc(a)                   __builtin_popcountll(a)


//SET PRECIOSION   cout << fixed ;  cout << setprecision(n) << ans << endl;


/// Ordered SET
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pref_trie;


///

ll big_mod(ll a,ll b, ll c){    if(b==0)    return 1;   if(b%2==0)  {   ll d=big_mod(a,b/2,c);      return ((d*d)%c);      }     return (((a%c)*big_mod(a,b-1,c))%c);}
double distance(double x1, double y1, double x2, double y2) {    double xx  = (x1-x2) * (x1-x2);     double yy  = (y1-y2) * (y1-y2);     return sqrt(xx+yy); }

int dx4[]={ 0,-1, 0, 1};
int dy4[]={-1, 0, 1, 0};

int dx8[]={1, 1, 2, 2,-1,-1,-2,-2};
int dy8[]={2,-2, 1,-1, 2,-2, 1,-1};

int Set(int n,int pos){ return n = n | (1<<pos);}
int reset(int n, int pos){ return n = n & ~(1<<pos);}
bool check(int n, int pos){ return (bool) (n & (1<<pos));}

rope<char> R[50010];
int v=0,o=0;
char ara[105],out[200005];

int main()
{
    //OUT
    int test;
    while(sf(test) != EOF)
    {
        v=0;
        lop1(t,test)
        {
            int q,p,c;
            sf(q);
            if(q == 1)
            {
                scanf("%d %s",&p,ara);
                v++;
                R[v] = R[v-1];
                R[v].insert(p,ara);///insert string ara after position p
            }
            else if(q == 2)
            {
                sff(p,c);
                v++;
                R[v] = R[v-1];
                R[v].erase(p-1,c);///Remove c characters starting at position p
            }
            else
            {
                int ver;
                sfff(ver,p,c);
                rope<char>sub = R[ver].substr(p-1,c); ///Print c characters starting at position p
                for(auto it: sub)
                {
                    out[o++] = it;
                }
                out[o++]=10;//new line
            }
        }
    }
    printf("%s",out);
    return 0;
}


