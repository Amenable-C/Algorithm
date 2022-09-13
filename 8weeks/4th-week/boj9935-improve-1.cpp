#include<bits/stdc++.h>
using namespace std;

string s, t, ret;
stack<char> stk;

int main(){
	cin >> s >> t;
	for(char a : s){
		stk.push(a);
		if(stk.size() >= t.size() && stk.top() == t[t.size() - 1]){
			string ss = "";
			for(char i : t){
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());
			
			if(t != ss){
				for(int i : ss){
					stk.push(i);
				}
			}
			
		}
	}
	if(stk.size()){
		string m = "";
		while(stk.size()){
			m += stk.top();
			stk.pop();	
		}
		reverse(m.begin(), m.end());
		cout << m;
	}
	else
		cout << "FRULA";
	return 0;
}
