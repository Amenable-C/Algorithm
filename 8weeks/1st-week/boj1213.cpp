#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	map<char, int> _map;
	char c;
	
	if(s.size() % 2 == 0){ // 짝수일 경우 
		for(int i = 0; i < s.size(); i++){
			_map[s[i]]++;	
		}
		for(auto it : _map){
			if(it.second % 2 != 0){
				cout << "I'm Sorry Hansoo";	
				return 0;
			}
		}
	}
	else{
		for(int i = 0; i < s.size(); i++){
			_map[s[i]]++;	
		}
		
		int check = 0;
		for(auto it : _map){
			if(it.second % 2 != 0){
				check++;
			}
			if(check == 2){
				cout << "I'm Sorry Hansoo";
				return 0;	
			}
		}
	}
	
	s = "";
	char odd = 'x';
	stack<char> _stack;
	
	for(auto it : _map){
		
		if(it.second % 2 != 0)
			odd = it.first;
		
		for(int i = 0; i < it.second / 2; i++){
			_stack.push(it.first);		
			s += it.first;
		}
	}
	
	if(odd != 'x')
		_stack.push(odd);
	
	while(!_stack.empty()){
		s += _stack.top();
		_stack.pop();
	}
	
	cout << s;
	
	return 0; 
	
}
