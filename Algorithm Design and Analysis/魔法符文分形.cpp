#include <bits/stdc++.h>
using namespace std;
char getChar(string &s, long long index, long long length){
    if(length <= s.length())
        return s[index - 1];
    long long half = length / 2;
    if(index <= half){
        return getChar(s, index, half);//如果字母在最终字符串左半边则直接寻找该位置
    }else{
        long long pos = index - half;
        if(pos == 1){
            return getChar(s, half, half);//如果字母在右半边第一位，那么该位即为上一次变换的末位
        }
        return getChar(s, pos - 1, half);
    }
}
int main(){
    string s;
    long long n;
    cin >> s >> n;
    long long len = s.length();
    while(len < n){
        len *= 2;
    }
    cout << getChar(s, n, len);
    return 0;
}