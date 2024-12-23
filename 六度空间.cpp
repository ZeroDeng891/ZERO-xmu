#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, m;
int step[N];
bool vis[N];
vector<int> adj[N];
void add(int a, int b){
    adj[a].push_back(b), adj[b].push_back(a);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n; i ++){
        queue<int> q;
        q.push(i);
        memset(step, -1, sizeof step);
        memset(vis, false, sizeof vis);
        step[i] = 0;
        while(!q.empty()){
            int t = q.front(); q.pop();
            vis[t] = true;
            for(int j : adj[t]){
                if(!vis[j]){
                    step[j] = step[t] + 1;
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
        int count = 0;
        for(int j = 1; j <= n; j ++){
            if(step[j] <= 6 && step[j] != -1)
                count ++;
        }
        printf("%d: %.2f%%\n", i, (double)count/n * 100.0);
    }
    return 0;
}