//Treap:
// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set
    ordered_set o_set;

    // insert function to insert in     // ordered set same as SET STL
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);

    // Finding the SECOND largest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1))          << endl;

    int a = *(o_set.find_by_order(10));
    cout << a << '\n';

    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4)          << endl;

    // Finding the count of elements less
    // than or equal to 4 i.e. striclty less
    // than 5 if integers are present
    cout << o_set.order_of_key(5)          << endl;

    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end())         o_set.erase(o_set.find(2));

    // Now after deleting 2 from the set
    // Finding the SECOND largest element in the set
    cout << *(o_set.find_by_order(1))          << endl;

    // Finding the number of
    // elements strictly less than k=4
    cout << o_set.order_of_key(4)          << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef trie< string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pref_trie base;
    base.insert("sun");
    string x;
    while(cin>>x)
    {
        if(x[0]=='?')
        {
            cout<<x.substr(1)<<endl;
            auto range=base.prefix_range(x.substr(1));
            int t=0;
            for(auto it=range.first; t<20 && it!=range.second; it++,t++)
                cout<<"  "<<*it<<endl;
        }
        else
            base.insert(x.substr(1));
    }

}
*/
