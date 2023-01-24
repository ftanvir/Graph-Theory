//LightOJ problem

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

const int N = 1e5+10;
// vector<int>g[N];
// bool vis[N];

void dfs(int s, vector<int>& g[], int & vis[]) {

    vis[s] = true;

    for(auto child:g[s]) {
        if(!vis[child]) {
            dfs(child, g, vis);
        }
    }

}

void cholokori()
{
    int n, m;
    cin>>n>>m;

    int sum = 0;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        sum+=num;
    }
    if(sum%n != 0) {
        cout<<"No"<<endl;
        return;
    }
    
    // g->clear();
    // for(int i=0; i<=n; i++) {
    //     vis[i] = false;
    // }

    vector<int>g[N];
    bool vis[N];   
    memset(vis, false, sizeof(vis));
    while(m--) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, g, vis);

    bool chk = true;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            chk = false;
            break;
        } 
    }

    if(chk) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }

}

int tc = 1;
int main()
{
    testcase{
        cout<<"Case "<<tc++<<": ";
        // g->clear();
        // memset(vis, false, sizeof(vis));
        cholokori();
    }
    return 0;
}