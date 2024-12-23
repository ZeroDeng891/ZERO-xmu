#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> node[N];
bool st[N];
int x, y;
void add(int a, int b){
    node[a].push_back(b), node[b].push_back(a);
}
bool hasRoute = false;
void dfs(int u){
    st[u] = true;
    if(u == y){
        hasRoute = true;
        return;
    }
    for(int i : node[u]){
        if(!st[i])
            dfs(i);
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
    cin >> x >> y;
    dfs(x);
    if(hasRoute)
        printf("There is a path between %d and %d.", x, y);
    else
        printf("There is no path between %d and %d.", x, y);
    return 0;
}