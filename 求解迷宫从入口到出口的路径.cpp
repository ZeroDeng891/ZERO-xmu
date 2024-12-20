#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
vector<PII> step;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main(){
    int n;
    cin >> n;
    int maze[n][n];
    bool isWalked[n][n] = {false};
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> maze[i][j];
    step.push_back({1, 1});
    isWalked[1][1] = true;
    bool canOut = true;
    while(!step.empty()){
        bool walked = false;
        PII cur = step.back();
        if(cur.first == n - 2 && cur.second == n - 2){
            break;
        }
        for(int i = 0; i < 4; i ++){
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if(nx > 0 && nx < n && ny > 0 && ny < n && maze[nx][ny] == 0 && !isWalked[nx][ny]){
                step.push_back(make_pair(nx, ny));
                walked = true, isWalked[nx][ny] = true;
                break;
            }
        }
        if(!walked)
            step.pop_back();
        if(step.empty())
            canOut = false;
    }
    if(canOut){
        for(int i = 0; i < step.size(); i ++){
            printf("(%d,%d)", step[i].first, step[i].second);
        }
    }
    else
        cout << "NO";
    return 0;
}