#include<bits/stdc++.h>
using namespace std;

int n;
string s, ret;
stack<char> stk;

int main(){
	for(int _t = 1; _t <= 10; _t++){
		ret = "";
		cin >> n;
		cin >> s;
		
		for(int i = 0; i < s.size(); i++){
			
			if(stk.size() && stk.top() == s[i]){
				stk.pop();
				continue;
			}
			
			stk.push(s[i]);
		}
		
		while(stk.size()){
			ret = stk.top() + ret;
			stk.pop();
		}
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
