#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int>g[N];
bool vis[N];
int comp[N];


void bfs(int s) {
    queue<int>q;
    q.push(s);
    vis[s]=true;
    comp[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i:g[u]) {
            if(!vis[i]) {
                vis[i] = true;
                comp[i] = u;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);
    
    if(!vis[n]) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int>route;
    int idx = n;
    while(idx!=1) {
        // cout<<idx<<" ";
        route.push_back(idx);
        idx = comp[idx];
    }
    route.push_back(1);
    int len = route.size();
    cout<<len<<endl;
    for(int i=route.size()-1; i>=0; i--) {
        cout<<route[i]<<" ";
    }cout<<endl;

    return 0;
}