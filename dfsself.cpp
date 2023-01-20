#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>g[N];
int vis[N];

void dfs(int source) 
{
    vis[source] = 1;
    cout<<source<<" -> ";
    for(auto it:g[source]) {
        if(vis[it]==0) {
            vis[it]=1;
            dfs(it);
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++) {
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source;
    cin>>source;
    dfs(source);
}