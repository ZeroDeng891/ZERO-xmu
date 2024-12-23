#include <bits/stdc++.h>
using namespace std;
const int N = 501;
const int INF = 0x3f3f3f3f;
int n, m, s, d;
int g[N][N], cost[N][N];
int dist[N], mcost[N];
bool st[N];
void init(){
    memset(dist, 0x3f, sizeof(dist));
    memset(mcost, 0x3f, sizeof(mcost));
    memset(g, 0x3f, sizeof g), memset(cost, 0x3f, sizeof cost);
}
void dijkstra(){
    dist[s] = 0;
    mcost[s] = 0;
    for(int i = 0; i < n - 1; i ++){
        int t = -1;
        for(int j = 0; j < n; j ++){
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        for(int j = 0; j < n; j ++){
            if(dist[j] > dist[t] + g[t][j] ||
               (dist[j] == dist[t] + g[t][j] && mcost[t] + cost[t][j] < mcost[j])){
                dist[j] = dist[t] + g[t][j];
                mcost[j] = mcost[t] + cost[t][j];
            }
        }
        st[t] = true;
    }
}
int main(){
    init();
    cin >> n >> m >> s >> d;
    for(int i = 0; i < m; i ++){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a][b] = g[b][a] = x;
        cost[a][b] = cost[b][a] = y;
    }
    dijkstra();
    cout << dist[d] << ' ' << mcost[d];
    return 0;
}
