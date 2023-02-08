#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int vis[N], clr[N];
vector <int> adj[N];
bool f;
void dfs(int node) {
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        int chld = adj[node][i];
        if (!vis[chld]) {
            clr[chld] = clr[node] ^ 1;
            dfs(chld);
        }
        else if (clr[chld] == clr[node]){
            f = 0;
        }
    }
}
int main()
{
    int t, cs = 0;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(clr, 0, sizeof(clr));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flg = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                f = 1;
                dfs(i);
                if (!f) {
                    flg = 0;
                    break;
                }
            }
        }
        cout << "Scenario #" << ++cs << ":\n";
        if (flg) {
            cout << "No suspicious bugs found!\n";
        }
        else {
            cout << "Suspicious bugs found!\n";
        }
        for (int i = 1; i <= n; i++) adj[i].clear();
    }
}