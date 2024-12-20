#include <bits/stdc++.h>
using namespace std;

struct stu{
    string num;
    int score, place, rankBig, rankSmall;
    stu(int x, int y): score(x), place(y){};
};

bool cmp(stu &a, stu &b){
    if(a.score != b.score) return a.score > b.score;
    else return a.num < b.num;
}

int main(){
    int n;
    cin >> n;
    vector<stu> res[n];
    for(int i = 0; i < n; i ++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j ++){
            string num;
            int score;
            cin >> num >> score;
            stu student(score, i + 1);
            student.num = num;
            res[i].push_back(student);
        }
    }
    for(int i = 0; i < n; i ++){
        sort(res[i].begin(), res[i].end(), cmp);
        for(int j = 0; j < res[i].size(); j ++){
            res[i][j].rankSmall = j + 1;
            if(j > 0 && res[i][j].score == res[i][j - 1].score)
                res[i][j].rankSmall = res[i][j - 1].rankSmall;
        }
    }

    vector<stu> all;
    for(int i = 0; i < n; i ++){
        all.insert(all.end(), res[i].begin(), res[i].end());
    }
    sort(all.begin(), all.end(), cmp);
    for(int i = 0; i < all.size(); i ++){
        all[i].rankBig = i + 1;
        if(i > 0 && all[i].score == all[i - 1].score)
            all[i].rankBig = all[i - 1].rankBig;
    }
    
    cout << all.size() << endl;
    for(int i = 0; i < all.size(); i ++){
        cout << all[i].num << ' ' << all[i].rankBig 
             << ' ' << all[i].place << ' ' << all[i].rankSmall << endl;
    }
    return 0;
}