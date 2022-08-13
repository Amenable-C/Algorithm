#include <bits/stdc++.h>
using namespace std;


string s;

bool check(string s){
	stack<char> stk;
	
	for(char c : s){
		if(c == '('){
			stk.push(c);
		}
		else if(c == '['){
			stk.push(c);
		}
		else if(c == ')'){
			if(!stk.empty() && stk.top() == '(')
				stk.pop();
			else
				return false;
		}
		else if(c == ']'){
			if(!stk.empty() && stk.top() == '[')
				stk.pop();
			else
				return false;
		}
	}
	
	return stk.empty();
	
}


int main(){
	getline(cin, s);	
	while(!(s.size() == 1 && s[0] == '.')){
		if(check(s))
			cout << "yes\n";
		else
			cout << "no\n";
		
		getline(cin, s);
	}
}
