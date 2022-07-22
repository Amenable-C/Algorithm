#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	if(s.size() == 1)
		cout << 1;
	
	
	for(int i = 0; i < s.size() / 2; i++){		
		if(s[i] != s[s.size() - i - 1]){   
			cout << 0;
			break;
		}	
		if(i == (s.size() / 2) - 1)
			cout << 1;
	}
	
	return 0;
}
