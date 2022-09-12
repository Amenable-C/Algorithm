#include<bits/stdc++.h>
using namespace std;

int n, d[200001], ret, cnt;
string s;
stack<int> stk;

int main(){
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			stk.push(i);
		else if(stk.size()){ // ')'인 경우 
			d[i] = d[stk.top()] = 1; // '해당 위치'와 '해당 위치와 매칭 되는 곳'을 '1'로 변경하는거 
			stk.pop();
		}
	}
	
	for(int i = 0; i < n; i++){
		if(d[i]){
			cnt++;
			ret = max(ret, cnt);
		}
		else
			cnt = 0;
	}
	
	cout << ret;
	return 0;
}
