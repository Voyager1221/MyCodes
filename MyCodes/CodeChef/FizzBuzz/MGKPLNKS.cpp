#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <set>
//#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <list>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef unsigned long long int ull;
#define I_am_Speed    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl          '\n'
#define INF           1e10
#define pb               push_back
#define ppb           pop_back
#define pf            push_front
#define ppf           pop_front
#define rs            resize
#define mt            make_tuple
#define g             get
#define forn(i,s,x)   for(int i=s; i<x; i++)
#define vdd           vector<vll>
#define oset          tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define tp3           tuple<ll,ll,ll>
#define tp2           tuple<ll,ll>
#define vll           vector<ll>
main()
{
    I_am_Speed;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        string s;
        cin>>s;
        ll w=0 ,b = 0;
        char prev = s[0];
        if(prev == 'B')
            b++;
        else
            w++;
        ll l = s.length();
        for(ll i = 1; i < l; i++)
        {
            if(s[i] == prev)
                continue;
            else if(s[i] == 'B')
            {
                b++;
                prev = 'B';
            }
            else
            {
                w++;
                prev = 'W';
            }
        }
        if(b<=w)
            cout<<b<<endl;
        else
            cout<<w<<endl;
    }
}
// c   C   %   5