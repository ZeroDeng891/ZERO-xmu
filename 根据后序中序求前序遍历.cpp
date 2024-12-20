#include <bits/stdc++.h>
using namespace std;
void dfs(int *a, int *b, int n){
    if(n == 0)
        return;
    cout << ' ' << a[n - 1];
    int i;
    for(i = 0; i < n && b[i] != a[n - 1]; i ++);
    dfs(a, b, i), dfs(a + i, b + i + 1, n - i - 1);
}
int main(){
    int n;
    cin >> n;
    int hou[n], zhong[n];
    for(int i = 0; i < n; i ++){
        cin >> hou[i];
    }
    for(int i = 0; i < n; i ++){
        cin >> zhong[i];
    }
    cout << "preorder:";
    dfs(hou, zhong, n);
    return 0;
}