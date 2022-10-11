#include<bits/stdc++.h>
using namespace std;

int flag;
string s;

int main(){
	cin >> s;
	for(int i = 0; i < s.size() / 2; i++){
		if(s[i] != s[s.size() - i - 1]){
			flag = 1;
			break;	
		}
	}
	
	if(flag)
		cout << 0;
	else
		cout << 1;
		
	return 0;
}
