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
			for(int i = 0; i < t.size(); i++){
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());
			
			if(!(ss == t)){
				for(char m : ss)
					stk.push(m);
			}
		}
	}
	
	if(!stk.size())
		cout << "FRULA";
	else{
		string ss = "";
		while(stk.size()){
			ss += stk.top();
			stk.pop();
		}
		reverse(ss.begin(), ss.end());
		cout << ss;
	}
}
