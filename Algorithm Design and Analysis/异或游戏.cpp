#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL solve(vector<int> &a, int bit){
    if(bit < 0)
        return 0;
    vector<int> group1, group0;
    for(int num : a){
        if(num & (1 << bit))
            group1.push_back(num);
        else
            group0.push_back(num);
    }
    if(group1.empty() || group0.empty()){
        return solve(a, bit - 1);
    }else{
        LL option1 = solve(group1, bit - 1);
        LL option2 = solve(group0, bit - 1);
        return (1 << bit) + min(option1, option2);
    }
}
int main(){
    cin >> n;
    vector<int> arr(n);
    int maxNum = -1;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }
    int bits = 0;
    while(maxNum != 0){
        maxNum = maxNum >> 1;
        bits ++;
    }
    cout << solve(arr, bits);
    return 0;
}