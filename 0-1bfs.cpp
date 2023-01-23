#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int inf = 1e9+10;


vector<pair<int,int>>g[N];
vector<int>d(N, inf);


void bfs(int s) 
{
    deque<int>q;
    q.push_front(s);
    d[s] = 0;

    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();

        for(auto child : g[v]) {
            int childNode= child.first;
            int childWt = child.second;

            if(d[v]+childWt < d[childNode]) {
                d[childNode] = d[v]+childWt;

                if(childWt==1) {
                    q.push_back(childNode);
                } else {
                    q.push_front(childNode);
                }
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;

    while(e--) {
        int u, v, wt;
        cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    int source;
    cin>>source;
    bfs(source);

    for(int i=0; i<n; i++) {
        cout<<d[i]<<endl;
    }
}