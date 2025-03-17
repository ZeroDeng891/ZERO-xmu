#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<bool> dp(N + 1, false);
void precompute(){
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j * j <= i; j ++){
            if(!dp[i - j * j]){
                dp[i] = true;
                break;
            }
        }
    }
}
int main(){
    precompute();
    int n;
    cin >> n;
    while(n --){
        int num;
        cin >> num;
        cout << (dp[num] ? "yes" : "no") << endl;
    }
    return 0;
}