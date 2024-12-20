#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int idx = 0, bgn = 0, size = 0;
int q[N] = {-1};
int main(){
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int word;
        cin >> word;
        bool find = false;
        for(int j = bgn; j < bgn + size; j ++)
            if(q[j] == word){
                find = true;
                break;
            }
        if(!find){
            if(size < m)
                q[idx ++] = word, size ++;
            else
                bgn ++, q[idx ++] = word;
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}