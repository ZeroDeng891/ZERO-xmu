#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int parent[n + 1];
    vector<int> kids[n + 1];
    int gen[n + 1] = {0};
    int ancestor;
    for(int i = 1; i <= n; i ++){
        cin >> parent[i];
        if(parent[i] == -1)
            ancestor = i;
        else
            kids[parent[i]].push_back(i);//易错
    }
    queue<int> q;
    q.push(ancestor);
    gen[ancestor] = 1;
    while(!q.empty()){
        int t = q.front(); 
        q.pop();
        for(size_t i = 0; i < kids[t].size(); i ++){
            gen[kids[t][i]] = gen[t] + 1;
            q.push(kids[t][i]);
        }
    }
    int maxGen = 0;
    for(int i = 1; i <= n; i ++){
        maxGen = max(maxGen, gen[i]);
    }
    vector<int> smallest;
    for(int i = 1; i <= n; i ++){
        if(gen[i] == maxGen)
            smallest.push_back(i);
    }
    cout << maxGen << endl;
    for(size_t i = 0; i < smallest.size(); i ++){
        if(i > 0) cout << ' ';
        cout << smallest[i];
    }
    return 0;
}