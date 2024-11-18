#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> adj[N];
bool st[N];
queue<int> q;
int n, m;
void add(int a, int b){
    adj[a].push_back(b), adj[b].push_back(a);
}
void dfs(int u){
    st[u] = true;
    q.push(u);
    sort(adj[u].begin(), adj[u].end());
    for(int i : adj[u]){
        if(!st[i]){
            dfs(i);
        }
    }
}
void bfs(int u){
    queue<int> qq;
    qq.push(u);
    st[u] = true;
    q.push(u);
    while(!qq.empty()){
        int tmp = qq.front();
        qq.pop();
        for(int i : adj[tmp]){
            if(!st[i]){
                st[i] = true;
                q.push(i);
                qq.push(i);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 0; i < n; i ++){
        if(!st[i]){
            dfs(i);
            cout << "{ ";
            while(!q.empty()){
                cout << q.front() << ' ';
                q.pop();
            }
            cout << "}" << endl;
        }
    }
    memset(st, false, sizeof(st));
    for(int i = 0; i < n; i ++){
        if(!st[i]){
            bfs(i);
            cout << "{ ";
            while(!q.empty()){
                cout << q.front() << ' ';
                q.pop();
            }
            cout << "}" << endl;
        }
    }
    return 0;
}