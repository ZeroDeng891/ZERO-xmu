#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> adj[N];
int d[N];
bool st[N];
void add(int a, int b){
    adj[a].push_back(b), adj[b].push_back(a);
}
void dfs(int u){
    st[u] = true;
    for(int i : adj[u]){
        if(!st[i]){
            dfs(i);
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    memset(d, 0, sizeof d);
    for(int i = 0; i < e; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[a] ++, d[b] ++;
    }
    dfs(1);
    bool connected = true;
    for(int i = 1; i <= n; i ++){
        if(!st[i]){
            connected = false;
            break;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(d[i] % 2 == 1){
            cnt ++;
        }
    }
    if((cnt == 2 || cnt == 0)&& connected){
        cout << "Y";
    }else{
        cout << "N";
    }
    return 0;
}