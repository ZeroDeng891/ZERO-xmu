#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int arr[N];
int n, k;
int bsearch(int l, int r){
    while(l < r){
        int mid = l + r >> 1;
        if(arr[mid] < k) l = mid + 1;
        else r = mid;
    }
    return l + 1;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    cout << bsearch(0, n);
    return 0;
}