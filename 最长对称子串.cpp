#include <iostream>
using namespace std;
int longest(string &s, int l, int r){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l --, r ++;
    }
    return r - l - 1;
}
int main(){
    string s;
    getline(cin, s);
    int result = 0;
    for(int i = 0; i < s.size(); i ++){
        int maxlen = max(longest(s, i, i), longest(s, i, i + 1));
        result = max(maxlen, result);
    }
    cout << result;
    return 0;
}