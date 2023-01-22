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

const int N = 1e5;
const int inf = 1e9;

int vis[8][8];
int lev[8][8];

int getX(string s) {
    return s[0]-'a';
}
int getY(string s) {
    return s[1] - '0';
}
void reset() 
{
    for(int i=0;i<8; i++) {
        for(int j=0; j<8; j++) {
            vis[i][j] = 0;
            lev[i][j] = inf;
        }
    }
}

vector<pair<int,int>> movements = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2, -1},
    {-1, 2} , {1, 2},
    {-1, -2} , {1, -2}
};

bool isValid(int x, int y) {
    return x>=0 && y>=0 && x<8 && y<8;
}

int bfs(string src, string dest) {
    int srcX = getX(src);
    int srcY = getY(src);

    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int,int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    lev[srcX][srcY] = 0;

    while(!q.empty()) 
    {
        pair<int,int> currNode = q.front();
        int x = currNode.ff, y = currNode.ss;   
        q.pop();

        for(auto movement : movements) {
            int childX = movement.ff+x;
            int childY = movement.ss+y;

            if(!isValid(childX, childY)) continue;

            if(!vis[childX][childY]) {

                q.push({childX, childY});
                vis[childX][childY] = 1;
                lev[childX][childY] = lev[x][y]+1;
            }
        }
        if(lev[destX][destY]!=inf) {
            break;
        }

    }

    return lev[destX][destY];
    
}

int main()
{
    testcase{
        reset();
        
        string s1, s2;
        cin>>s1>>s2;

        cout<<bfs(s1, s2)<<nl;
    }
    return 0;
}