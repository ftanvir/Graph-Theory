#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int g[N][N];

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int u, v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1; 
    }
    if(g[1][4]) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}