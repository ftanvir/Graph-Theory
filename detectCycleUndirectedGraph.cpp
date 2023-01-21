#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
bool vis[N];


bool dfs(int source, int parent) {

    vis[source] = 1;
    bool isCycle = false;
    for(auto child:g[source]) {
        if(vis[child] && child == parent) continue;
        if(vis[child] && child!=parent) {
            return true;
        }

        isCycle |= dfs(child, source);  //storing final result as true with or operation. if any condition return true;
    }
    return isCycle;
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
    
    bool isCyclic = false;
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        if(dfs(i, -1)) {
            isCyclic = true;
            break;
        }
    }
    
    if(isCyclic) {
        cout<<"It is a Cyclic Graph"<<endl;
    } else {
        cout<<"Cycle doesn't exist in graph"<<endl;
    }

    return 0;
}