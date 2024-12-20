#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node{
    int val, p, np;
};
node L[N];
vector<node> dL;
int main(){
    int head, n;
    cin >> head >> n;
    for(int i = 0; i < n; i ++){
        int add, x, neAdd;
        cin >> add >> x >> neAdd;
        L[add].val = x, L[add].np = neAdd;
    }
    int pt = head;
    while(pt != -1){
        int tmp = pt;
        while(L[tmp].np != -1){
            int tt = L[L[tmp].np].val;
            if(abs(tt) == abs(L[pt].val)){
                node temp;
                temp.p = L[tmp].np, temp.val = tt, temp.np = L[L[tmp].np].np;
                dL.push_back(temp);
                L[tmp].np = L[L[tmp].np].np;
            }
            tmp = L[tmp].np;
        }
        pt = L[pt].np;
    }
    pt = head;
    while(pt != -1){
        if(L[pt].np == -1)
            printf("%05d %d %d\n", pt, L[pt].val, L[pt].np);
        else
            printf("%05d %d %05d\n", pt, L[pt].val, L[pt].np);
        pt = L[pt].np;
    }
    for(int i = 0; i < dL.size(); i ++){
        printf("%05d %d ", dL[i].p, dL[i].val);
        if(i < dL.size() - 1)
            printf("%05d\n", dL[i + 1].p);
    }
    cout << "-1" << endl;
    return 0;
}