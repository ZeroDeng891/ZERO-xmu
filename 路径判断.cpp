#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int n, e, a, b;
vector<int> adj[N];
bool st[N], found;
vector<int> q;
void add(int x, int y){
    adj[x].push_back(y), adj[y].push_back(x);
}
void dfs(int u){
    st[u] = true;
    q.push_back(u);
    if(u == b){
        found = true;
        return;
    }
    for(int i : adj[u]){
        if(!st[i]){
            dfs(i);
        }
    }
}
int main(){
    cin >> n >> e;
    for(int i = 0; i < e; i ++){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    cin >> a >> b;
    dfs(a);
    if(found)
        printf("There is a path between %d and %d.", a, b);
    else
        printf("There is no path between %d and %d.", a, b);
    return 0;
}