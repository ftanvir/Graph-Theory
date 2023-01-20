#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
bool vis[N], flag = true;
int color[N];



void dfs(int s) 
{
    vis[s] = 1;
    for(auto i:g[s]) {
        if(!vis[i]) {
            color[i] = color[s] ^1;
            dfs(i);
        } else {
            if(color[i]==color[s]) {
                flag = false;
            }
        }
    }
}

int main()
{
    int n , e;
    cin>>n>>e;
    while(e--) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);        
    }


    dfs(1);

    if(flag) cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;



    return 0;
}