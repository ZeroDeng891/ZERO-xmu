#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int curLen = 1, maxLen = 1, endMax = 0;
    for(int i = 1; i < n; i ++){
        if(a[i] > a[i - 1]){
            curLen ++;
            if(curLen > maxLen){
                maxLen = curLen;
                endMax = i;
            }
        }
        else
            curLen = 1;
    }
    for(int i = endMax - maxLen + 1; i <= endMax; i ++){
        if(i > endMax - maxLen + 1) cout << ' ';
        cout << a[i];
    }
    return 0;
}