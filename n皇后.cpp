#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n;
int cnt = 0;
char board[N][N];
bool st1[N], st2[N], st3[N];
void dfs(int u){
    if(u == n){
        cnt ++;
        return;
    }
    for(int i = 0; i < n; i ++){
        if(!st1[i] && !st2[u + i] && !st3[u - i + n - 1] && board[u][i] == '*'){
            st1[i] = st2[u + i] = st3[u - i + n - 1] = true;
            dfs(u + 1);
            st1[i] = st2[u + i] = st3[u - i + n - 1] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << cnt;
    return 0;
}