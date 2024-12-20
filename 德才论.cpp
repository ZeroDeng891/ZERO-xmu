#include <bits/stdc++.h>
using namespace std;
struct stu{
    int num, de, cai, sum;
    int type;
    stu(int x, int y, int z): 
        num(x), de(y), cai(z), type(-1), sum(y + z){};
};

bool cmp(stu &s1, stu &s2){
    if(s1.type != s2.type)
        return s1.type < s2.type;
    else if(s1.sum != s2.sum)
        return s1.sum > s2.sum;
    else if(s1.de != s2.de) 
        return s1.de > s2.de;
    else
        return s1.num < s2.num;
}
int main(){
    int n, l, h;
    cin >> n >> l >> h;
    vector<stu> stus;
    for(int i = 0; i < n; i ++){
        int num, de, cai;
        cin >> num >> de >> cai;
        if(de < l || cai < l)
            continue;
        stu s(num, de, cai);
        if(de >= h && cai >= h)
            s.type = 1;
        else if(de >= h && cai < h)
            s.type = 2;
        else if(de >= cai)
            s.type = 3;
        else
            s.type = 4;
        stus.push_back(s);
    }
    sort(stus.begin(), stus.end(), cmp);
    cout << stus.size() << endl;
    for(int i = 0; i < stus.size(); i ++){
        cout << stus[i].num << ' ' << stus[i].de << ' ' << stus[i].cai << endl;
    }
    return 0;
}