#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret, d[200004];
string s;
stack<int> _s;

int main(){
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			_s.push(i);
		else if(_s.size()){
			d[i] = d[_s.top()] = 1;
			_s.pop();
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
