#include <bits/stdc++.h>
using namespace std;
int ace(string &s, char c, int l, int r){
	if(l == r){
		if(s[l] == c)
			return 0;
		else
			return 1;
	}
	int cnt_left = 0, cnt_right = 0;
	for(int i = l; i <= (l + r) / 2; i ++){
		if(s[i] != c) cnt_left ++;
	}
	for(int i = r; i >= (l + r) / 2 + 1; i --){
		if(s[i] != c) cnt_right ++;
	}
	int cost1 = cnt_left + ace(s, c + 1, (l + r) / 2 + 1, r);
	int cost2 = cnt_right + ace(s, c + 1, l, (l + r) / 2);
	return min(cost1, cost2);
}
int main(){
	int n;
	cin >> n;
	while(n --){
		int num;
		cin >> num;
		string str;
		cin >> str;
		cout << ace(str, 'a', 0, num - 1) << endl;
	}
	return 0;
}