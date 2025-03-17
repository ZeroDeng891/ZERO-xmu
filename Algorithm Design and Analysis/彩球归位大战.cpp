#include <bits/stdc++.h>
using namespace std;
const int max_N = 200000;
vector<vector<int>> pos(max_N + 1);
vector<queue<int>> box(max_N + 1);
queue<int> pop_color;
int main(){
    //输入部分
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= q; i ++){
        int num;
        cin >> num;
        while(num --){
            int color;
            cin >> color;
            box[i].push(color);
        }
    }
    //处理部分
    for(int i = 1; i <= q; i ++){
        int top = box[i].front();
        pos[top].push_back(i);
        if(pos[top].size() == 2)
            pop_color.push(top);
    }
    while(!pop_color.empty()){
        int color = pop_color.front();
        pop_color.pop();
        for(int i : pos[color]){
            box[i].pop();
            if(!box[i].empty()){
                int front_color = box[i].front();
                pos[front_color].push_back(i);
                if(pos[front_color].size() == 2){
                    pop_color.push(front_color);
                }
            }
        }
    }
    bool isEmpty = true;
    for(int i = 1; i <= q; i ++){
        if(!box[i].empty())
            isEmpty = false;
    }
    cout << (isEmpty ? "Yes" : "No");
    return 0;
}