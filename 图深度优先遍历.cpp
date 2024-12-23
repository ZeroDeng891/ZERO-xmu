#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
vector<int> node[N];
bool st[N];
void add(int a, int b){
    node[a].push_back(b);
}
void dfs(int a){
    cout << a << ' ';
    st[a] = true;
    for(int i = 0; i < node[a].size(); i ++){
        int t = node[a][i];
        if(!st[t]){
            dfs(t);
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 0; i < n; i ++){
        sort(node[i].begin(), node[i].end());
    }
    memset(st, false, sizeof st);
    for(int i = 0; i < n; i ++){
        if(!st[i])
            dfs(i);
    }
    return 0;
}