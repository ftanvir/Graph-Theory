// //LightOJ problem
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector <int> adj[N];
bool vis[N];
int sz, ttl;
int a[N];
void dfs(int node) {
    vis[node] = 1;
    sz++;
    ttl += a[node];
    for (int i = 0; i < adj[node].size(); i++) {
        int chld = adj[node][i];
        if (!vis[chld]) {
            dfs(chld);
        }
    }
}
void tc(int cs) {
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> v;
    bool flg = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sz = 0, ttl = 0;
            dfs(i);
            if (ttl % sz) {
                flg = 0;
                break;
            }
            else v.push_back(ttl / sz);
        }
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i-1]) {
            flg = 0;
            break;
        }
    }
    cout << "Case " << cs << ": ";
    (flg) ? cout << "Yes\n" : cout << "No\n";
    for (int i = 1; i <= n; i++)adj[i].clear();
}
int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        tc(++cs);
    }
}
