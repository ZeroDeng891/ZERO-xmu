#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> M[N];
bool st[N];
void add(int a, int b){
    M[a].push_back(b), M[b].push_back(a);
}
void dfs(int a){
    cout << a << ' ';
    st[a] = true;
    for(int i = 0; i < M[a].size(); i ++){
        int t = M[a][i];
        if(!st[t]){
            dfs(t);
        }
    }
}
void bfs(int a){
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int t = q.front(); q.pop();
        cout << t << ' ';
        st[t] = true;
        for(int i = 0; i < M[t].size(); i ++){
            int tt = M[t][i];
            if(!st[tt]){
                q.push(tt);
                st[tt] = true;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    memset(st, false, sizeof st);
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 0; i < n; i ++){
        sort(M[i].begin(), M[i].end());
    }
    for(int i = 0; i < n; i ++){
        if(!st[i]){
            cout << "{ ";
            dfs(i);
            cout << "}" << endl;
        }
    }
    memset(st, false, sizeof st);
    for(int i = 0; i < n; i ++){
        if(!st[i]){
            cout << "{ ";
            bfs(i);
            cout << "}" << endl;
        }
    }
    return 0;
}