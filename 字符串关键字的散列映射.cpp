#include <bits/stdc++.h>
using namespace std;
const int N = 510;
bool Hash[N];
unordered_map<string, int> m;
int HKey(string &s, int p)
{
    if (m.count(s) == 1)
        return m[s];
    string temp = s;
    reverse(temp.begin(), temp.end());
    int cnt = 0, f = 0;
    for (auto i : temp)
    {
        f += (i - 'A') * pow(32, cnt++);
        if (cnt == 3)
            break;
    }
    f = f % p;

    int k, tmp;
    k = 1;
    tmp = f;
    while (Hash[tmp])
    {
        tmp = f;
        if (k % 2 != 0)
        { // 奇数为正
            tmp = (tmp + (int)pow((k + 1) / 2, 2)) % p;
        }
        else
        { // 偶数为负
            tmp = (tmp - (int)pow((k + 1) / 2, 2) + p) % p;
        }
        k++;
    }
    Hash[tmp] = true; // 存入tmp位置
    m[s] = tmp;
    return tmp;
}
int main()
{
    int n, p;
    cin >> n >> p;
    memset(Hash, false, sizeof(Hash));
    int res[n];
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        res[i] = HKey(str, p);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << res[i];
        else
            cout << ' ' << res[i];
    }
    return 0;
}