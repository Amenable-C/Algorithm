#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	
	cin >> s;
	if(s.size() == 1){
		cout << 1;
		return 0;
	}
		
	for(int i = 0; i < s.size() / 2; i++){
		
		if(s[i] != s[s.size() - i - 1]){
			cout << 0;
			return 0;
		}	
	}
	
	cout << 1;
	return 0;
}
