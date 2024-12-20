#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int idx, head, e[N], ne[N];
void init(){
    idx = 0, head = -1;
}
void insert(int num){
    e[idx] = num, ne[idx] = head, head = idx ++;
}
void deleteNode(int t){
    ne[t] = ne[ne[t]];
}
int main(){
    int n, p;
    cin >> n >> p;
    init();
    for(int i = n; i >=1; i --){
        insert(i);
    }
    ne[0] = head;
    int pt = head;
    for(int i = 0; i < n; i ++){
        int tt = p - 2;
        while(tt --){
            pt = ne[pt];
        }
        if(i > 0) cout << ' ';
        cout << e[ne[pt]];
        deleteNode(pt);
        pt = ne[pt];
    }
    return 0;
}