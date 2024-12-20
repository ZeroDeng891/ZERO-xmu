#include <iostream>
#include <map>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    map<pair<int, int>, int> matrix;
    int n1, n2;
    cin >> n1;
    for(int i = 0; i < n1; i ++){
        int r, c, value;
        cin >> r >> c >> value;
        matrix[{r, c}] = value;
    }
    cin >> n2;
    for(int i = 0; i < n2; i ++){
        int r, c, value;
        cin >> r >> c >> value;
        matrix[{r, c}] += value;
    }
    int cnt = 0;
    for (const auto& element : matrix) {
        if (element.second != 0) {
            cnt ++;
        }
    }
    cout << cnt << endl;
    for (const auto& element : matrix) {
        if (element.second != 0) {
            cout << element.first.first << ' '
                 << element.first.second << ' '
                 << element.second << endl;
        }
    }
    return 0;
}