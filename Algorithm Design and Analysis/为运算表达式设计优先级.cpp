#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> operate(const string &str){
    bool isNumber = true;
    vector<int> result;
    for(int i = 0; i < str.length(); i ++){
        char c = str[i];
        if(c == '+' || c == '-' || c == '*'){
            isNumber = false;
            vector<int> left = operate(str.substr(0, i));
            vector<int> right = operate(str.substr(i + 1));
            for(int l : left){
                for(int r : right){
                    if(c == '+')
                        result.push_back(l + r);
                    if(c == '-')
                        result.push_back(l - r);
                    if(c == '*')
                        result.push_back(l * r);
                }
            }
        }
    }
    if(isNumber)
        result.push_back(stoi(str));
    return result;
}
int main(){
    cin >> s;
    vector<int> result = operate(s);
    sort(result.begin(), result.end());
    for(int number : result){
        cout << number << endl;
    }
    return 0;
}