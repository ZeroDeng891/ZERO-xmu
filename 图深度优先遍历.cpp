#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
int n, e;
vector<int> node[N];
bool st[N];
queue<int> q;
void add(int a, int b){
    node[a].push_back(b);
}
void dfs(int u){
    st[u] = true;
    q.push(u);
    sort(node[u].begin(), node[u].end());
    for(int i : node[u]){
        if(!st[i]){
            dfs(i);
        }
    }
}
int main(){
    cin >> n >> e;
    for(int i = 0; i < e; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 0; i < n; i ++){
        if(!st[i])
            dfs(i);
    }
    while(q.size()){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}