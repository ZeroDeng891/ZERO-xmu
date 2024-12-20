#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> p;
    string input;
    bool ok = true;
    while(cin >> input){
        if(input == "#") break;
        if(isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))){
            p.push(stoi(input));
        }
        else{
            if(p.size() < 2){
                cout << "Expression Error: " << p.top();
                ok = false;
                break;
            }
            if(input == "+"){
                int a = p.top();
                p.pop();
                int b = p.top();
                p.pop();
                p.push(a + b);
            }
            else if(input == "-"){
                int a = p.top();
                p.pop();
                int b = p.top();
                p.pop();
                p.push(b - a);
            }
            else if(input == "*"){
                int a = p.top();
                p.pop();
                int b = p.top();
                p.pop();
                p.push(a * b);
            }
            else if(input == "/"){
                int a = p.top();
                p.pop();
                int b = p.top();
                p.pop();
                if(a == 0){
                    printf("Error: %d/0", b);
                    ok = false;
                    break;
                }
                p.push(b / a);
            }
        }
    }
   if(ok) {
        if(p.size() != 1) {
            cout << "Expression Error: " << p.top();
        } else {
            cout << p.top();
        }
    }
    return 0;
}