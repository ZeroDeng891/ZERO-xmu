#include <bits/stdc++.h>
using namespace std;
bool isSame(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); i ++)
        if(a[i] != b[i])
            return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> origin, inter;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        origin.push_back(num);
    }
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        inter.push_back(num);
    }
    int i;
    for(i = 1; i < inter.size() && inter[i - 1] <= inter[i]; i ++);
    int k = i;
    bool isInsert = true;
    for(; i < inter.size(); i ++)
        if(inter[i] != origin[i])
            isInsert = false;
    if(isInsert){
        cout << "Insertion Sort" << endl;
        sort(inter.begin(), inter.begin() + k + 1);
    }
    else{
        cout << "Heap Sort" << endl;
        vector<int> tmp = origin;
        for(int j = tmp.size(); j > 0; j --){
            make_heap(tmp.begin(), tmp.begin() + j);
            pop_heap(tmp.begin(), tmp.begin() + j);
            if(isSame(inter, tmp)){
                make_heap(tmp.begin(), tmp.begin() + j - 1);
                pop_heap(tmp.begin(), tmp.begin() + j - 1);
                inter = tmp;
                break;
            }
        }
    }
    for(int j = 0; j < inter.size(); j ++){
        if(j > 0) cout << " ";
        cout << inter[j];
    }
    return 0;
}