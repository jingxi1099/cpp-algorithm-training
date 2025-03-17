#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

constexpr int N = 410;

queue<PII> q;
int dict[N][N];
bool vis[N][N];

int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {-1,1,-1,1,-2,2,-2,2};

bool valid(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m && vis[n][y] == false);
}

void solve(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    
    dict[x][y] = 0;
    vis[x][y] = true;
    
    q.push({x,y});
    
    while(!q.empty()){
        auto [x1,y1] = q.front();
        q.pop();
        
        if(valid(x1,y1)){
            for(int i = 0; i < 8; i++){
                int nx = x1 + dx[i];
                int ny = y1 + dy[i];
                
                if(valid(x1,y1)){
                    dict[nx][ny] = dict[x1][y1] + 1;
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }else{
                    continue;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << dict[i][j] << (j == m ? "\n" : "    ");
        }
        cout << "\n";
    }
    
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    solve();
    
    return 0;
}
