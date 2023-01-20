#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>g[N];
int vis[N];


void bfs(int s) {
    queue<int>q;
    q.push(s);
    cout<<s<<' ';
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto i:g[u]) {
            if(!vis[i]) {
                vis[i] = 1;
                q.push(i);
                cout<<i<<' ';
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    while (e--)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int source;
    cin>>source;
    bfs(source);
    
}
