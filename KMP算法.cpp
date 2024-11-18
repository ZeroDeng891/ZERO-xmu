#include <iostream>
using namespace std;
/* 学习Y总的KMP算法模板 */
int N = 10010;
int M = 10010;
int main(){
    int n, m;
    char p[N], s[M];
    cin >> n >> p + 1 >> m >> s + 1;
    int ne[n + 1];
    ne[0] = ne[1] = 0;
    for(int i = 2, j = 0; i <= n; i ++){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i ++){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j ++;
        if(j == n){
            j = ne[j];
            cout << i - n << ' ';
        }
    }
    return 0;
}