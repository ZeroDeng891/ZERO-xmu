#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

int main() {
    unordered_map<LLI, string> accounts;
    int n;
    cin >> n;
    
    while(n--) {
        char op;
        LLI num;
        string pwd;
        cin >> op >> num >> pwd;
        
        if(op == 'N') {
            if(accounts.count(num) == 0) {
                accounts[num] = pwd;
                cout << "New: OK" << endl;
            } else {
                cout << "ERROR: Exist" << endl;
            }
        } else { // op == 'L'
            if(accounts.count(num) == 0) {
                cout << "ERROR: Not Exist" << endl;
            } else if(accounts[num] != pwd) {
                cout << "ERROR: Wrong PW" << endl;
            } else {
                cout << "Login: OK" << endl;
            }
        }
    }
    return 0;
}