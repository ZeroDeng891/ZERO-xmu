#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int g[N][N];
int co[N][N];
int dist[N];
int cost[N];
bool st[N];

void dijkstra(int s, int n){
    memset(dist, INF, sizeof dist);
    memset(cost, INF, sizeof cost);
    memset(st, false, sizeof st);
    dist[s] = 0;
    cost[s] = 0;
    for(int i = 0; i < n - 1; i ++){
        int t = -1;
        for(int j = 1; j <= n; j ++){
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        for(int j = 1; j <= n; j ++){
            if(dist[j] > dist[t] + g[t][j]){
                dist[j] = dist[t] + g[t][j];
                cost[j] = cost[t] + co[t][j];
            }
            else if(dist[j] == dist[t] + g[t][j])
                cost[j] = min(cost[j], cost[t] + co[t][j]);
        }
        st[t] = true;
    }
}

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for(int i = 0; i < m; i ++){
        int a, b, distance, fee;
        cin >> a >> b >> distance >> fee;
        g[a][b] = g[b][a] = distance;
        co[a][b] = co[b][a] = fee;
    }

    dijkstra(s, n);

    cout << dist[d] << ' ' << cost[d];
    return 0;
}