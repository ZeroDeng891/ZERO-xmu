#include <bits/stdc++.h>
using namespace std;
const int N = 66;
int num;
int sum = 0;
vector<int> sticks;
bool used[N];

bool splice(int cnt, int curLen, int target, int groups){
    if(cnt == groups - 1)
        return true;
    if(curLen == target)
        return splice(cnt + 1, 0, target, groups);
    int prev = -1;
    for(int i = 0; i < sticks.size(); i ++){
        int curStick = sticks[i];
        if(!used[i] && curStick != prev && curLen + curStick <= target){
            used[i] = true;
            if(splice(cnt, curLen + curStick, target, groups))
                return true;
            used[i] = false;
            prev = curStick;
            if(curLen == 0)
                return false;
        }
    }
    
    return false;
}

int main(){
    cin >> num;
    for(int i = 0; i < num; i ++){
        int stk;
        cin >> stk;
        sticks.push_back(stk);
        sum += stk;
    }
    sort(sticks.begin(), sticks.end(), greater<int>());

    for(int len = sticks[0]; len <= sum; len ++){
        if(sum % len == 0){
            memset(used, false, sizeof used);
            if(splice(0, 0, len, sum / len)){
                cout << len;
                break;
            }
        }
    }
    return 0;
}