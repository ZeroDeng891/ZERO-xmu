#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> s1, s2;
    int num;
    do{
        cin >> num;
        s1.push_back(num);
    }while(num != -1);
    do{
        cin >> num;
        s2.push_back(num);
    }while(num != -1);
    vector<int> out;
    int p = 0, q = 0;
    while(s1[p] != -1){
        if(s2[q] > s1[p])
            p ++;
        else if(s2[q] < s1[p])
            q ++;
        else{
            out.push_back(s1[p]);
            p ++, q ++;
        }
    }
    if(!out.empty())
        for(int i = 0; i < out.size(); i ++){
            if(i > 0) cout << ' ';
            cout << out[i];
        }
    else
        cout << "NULL";
    return 0;
}