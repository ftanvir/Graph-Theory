#include <bits/stdc++.h>
using namespace std;

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

const int mxn = 25;
char arr[mxn][mxn];
bool vis[mxn][mxn];

int w, h, cnt;

bool isValid(int x, int y)
{
    if(x>=0 && x<h && y>=0 && y<w && arr[x][y]!='#' && !vis[x][y]) return true;

    return false;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;
    cnt++;
    for(int k=0; k<4; k++) {
        int x = i+dx[k];
        int y = i+dy[k];
        if(isValid(x, y)) {
            dfs(x, y);
        }
    }

}

int main()
{
    int tc=1;
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        cin>>w>>h;
        int srcX, srcY;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(arr[i][j]=='@') {
                    srcX = i;
                    srcY = j;
                }
            }
        }
        cnt = 0;

        dfs(srcX, srcY);

        cout<<"Case "<<tc++<<": "<<cnt<<endl;
    }
}