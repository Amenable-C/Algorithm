#include<bits/stdc++.h>
using namespace std;

int n, ret;
string s;
stack<char> stk;

int main(){
	cin >> n;
	while(n--){
		while(stk.size()){
			stk.pop();	
		}
		
		cin >> s;		
		for(int i = 0; i < s.size(); i++){
			if(!stk.size()){
				stk.push(s[i]);
				continue;	
			}
			else{
				if(stk.top() == s[i]){
					stk.pop();
				}
				else{
					stk.push(s[i]);	
				}
			}
		}
		if(!stk.size())
			ret++;
	}
	cout << ret;
	return 0;
}
