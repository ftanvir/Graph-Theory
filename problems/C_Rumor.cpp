//codeforces problem 893C
#include <bits/stdc++.h>
using namespace std;

/**----data type----*/
#define ll long long int
#define llu unsigned long long int

#define fast      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi          acos(-1.0)
#define nl          '\n'
/**-------Shortend Library-------*/
#define vi vector<int>
#define mii map<int, int>
#define f(i,n) for(ll i=0; i<n; i++)
#define FOR(i, a, b) for(ll i=a; i<=b; i++)
#define testcase ll t;cin>>t;while(t--)

#define ff first
#define ss second
#define all(a)         a.begin(),a.end()
#define Sort(x)        sort(x.begin(),x.end())
#define SortR(x)       sort(x.begin(),x.end(),greater<int>())
#define Reverse(x)     reverse(x.begin(),x.end())

#define SortA(ar,s)    sort(ar,ar+s)
#define SortD(ar,s)    sort(ar,ar+s,greater<int>())

#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       (a*(b/gcd(a,b)))
#define sq(x)          (x)*(x)
#define mid(l,r)       (l+(r-l)/2)

#define leftShift(p)         (p<<1)
#define rightShift(p)        (p>>1)

#define min3(a,b,c)       min(a,min(b,c))
#define min4(a,b,c,d)     min(a,min(b,min(c,d)))
#define max3(a,b,c)       max(a,max(b,c))
#define max4(a,b,c,d)     max(a,max(b,max(c,d)))
#define pb(x)             push_back(x)
#define mod               1e8+7
#define precision(x)      cout<<fixed<<setprecision(x)
#define yes               cout<<"YES"<<nl
#define no                cout<<"NO"<<nl
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>

/**----Functions to use----**/
ll powerLog(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power%2)
        {
            res *= base;
            power--;
        } else 
        {
            base *=base;
            power/=2;
        }
    }
    return res;
}

const ll N = 1e5+10;

vector<ll>g[N];
bool vis[N];

void dfs(ll source)
{
    vis[source] = true;

    for(auto child:g[source]) {
        if(!vis[child]) {
            dfs(child);
        }
    }
}

void cholokori()
{
    // memset(vis, false, sizeof(vis));
    ll n, m;
    cin>>n>>m;
    vector<pair<ll,ll>>cost; //cost, index;
    ll sum = 0;
    for(int i=1; i<=n; i++) {
        int num;
        cin>>num;

        cost.push_back({num, i});
        sum+=num;
    }
    sort(all(cost));
    if(m==0) {
        cout<<sum<<nl;
        return;
    }

    while(m--) {
        ll u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans=0;

    for(auto it:cost) {
        if(!vis[it.ss]) {
            // cout<<it.ss<<" ";
            ans+=it.ff;
            dfs(it.ss);
        }
    }

    cout<<ans<<nl;

}

int main()
{
    cholokori();
    return 0;
}