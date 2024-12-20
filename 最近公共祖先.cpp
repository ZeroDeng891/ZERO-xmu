#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int tr[n + 1];
    for(int i = 1; i <= n; i ++){
        cin >> tr[i];
    }
    int n1, n2;
    cin >> n1 >> n2;
    if(!tr[n1] || !tr[n2]){
        printf("ERROR: T[%d] is NULL", tr[n1] == 0 ? n1: n2);
        return 0;
    }
    while(n1 != n2){
        if(n1 > n2)
            n1 = n1 / 2;
        else if(n1 < n2)
            n2 = n2 / 2;
    }
    if(tr[n1] == 0)
        printf("ERROR: T[%d] is NULL", n1);
    else
        printf("%d %d", n1, tr[n1]);
    return 0;
}