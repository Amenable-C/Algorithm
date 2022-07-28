#include <bits/stdc++.h>
using namespace std;

map<char, int> _map;
int n, a, b, total; 
string s;
bool ch = false;
bool result = true;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		
		for(int j = 0; j < s.size(); j++){
			
			if(j > 0 && s[j-1] != s[j])
				ch = true;
				
			if(ch == true && _map['A'] > 1 && _map['B'] > 1 && _map['A'] % 2 != 0 && _map['B'] % 2 != 0)
				result = false;
			
			_map[s[j]]++;	
			ch = false;
		}
		
		if(result && _map['A'] % 2 == 0 && _map['B'] % 2 == 0)
			total++;
		else
			result = true;
			
		_map.clear();
	}
	
	cout << total;
}
