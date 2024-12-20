#include <bits/stdc++.h>
using namespace std;
struct node{
    int l = -1, r = -1;
};
int main(){
    int n;
    cin >> n;
    vector<node> tree(n);
    bool isChild[n];
    for(int i = 0; i < n; i ++){
        char left, right;
        cin >> left >> right;
        if(isdigit(left)){
            tree[i].l = left - '0';
            isChild[left - '0'] = true;
        }
        if(isdigit(right)){
            tree[i].r = right - '0';
            isChild[right - '0'] = true;
        }
    }
    int root;
    for(int i = 0; i < n; i ++){
        if(!isChild[i]){
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    bool first = true;;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(tree[t].l == -1 && tree[t].r == -1){
            if(first){
                cout << t;
                first = false;
            }
            else
                cout << ' ' << t;
        }
        else{//attention
            if(tree[t].l != -1)
                q.push(tree[t].l);
            if(tree[t].r != -1)
                q.push(tree[t].r);
        }
    }
    return 0;
}