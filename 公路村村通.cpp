#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];
int prim(){
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i ++){
        int t = -1;
        for(int j = 1; j <= n; j ++){
            if(!st[j] && (t == -1|| dist[j] < dist[t]))
                t = j;
        }
        if(dist[t] == INF) return INF;
        res += dist[t];
        st[t] = true;
        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    int result = prim();
    if(result == INF) cout << "-1";
    else cout << result;
    return 0;
}