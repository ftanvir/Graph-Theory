#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];

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
    // if(g[1][4]) {
    //     cout<<"YES"<<endl;
    // } else {
    //     cout<<"NO"<<endl;
    // }
}