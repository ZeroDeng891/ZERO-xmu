#include <bits/stdc++.h>
using namespace std;
int main(){
    string os, op;
    cin >> os >> op;
    int n = os.size(), m = op.size();
    char s[n + 1], p[m + 1];
    int ne[m + 1] = {0};
    for(int i = 1; i <= n; i ++){
        s[i] = os[i - 1];
    }
    for(int i = 1; i <= m; i ++){
        p[i] = op[i - 1];
    }
    vector<int> oc;
    for(int i = 2, j = 0; i <= m; i ++){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i ++){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j ++;
        if(j == m){
            j = ne[j];
            oc.push_back(i - m + 1);
        }
    }
    for(int i = 0; i < oc.size(); i ++)
        cout << oc[i] << endl;
    for(int i = 1; i <= m; i ++){
        if(i > 1) cout << ' ';
        cout << ne[i];
    }
    return 0;
}