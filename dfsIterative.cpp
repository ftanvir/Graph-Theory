#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>g[N];
bool vis[N];

void dfs(int source) {
    stack<int>st;
    st.push(source);
    while(!st.empty()) {
        int top = st.top();
        if(!vis[top]) {
            cout<<top<<" ";
        }
        vis[top] = 1;
        st.pop();
        for(auto it:g[top]) {
            if(!vis[it]) {
                st.push(it);
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int source;
    cin>>source;
    dfs(source);
    return 0;
}