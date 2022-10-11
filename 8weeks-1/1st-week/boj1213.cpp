#include<bits/stdc++.h>
using namespace std;

int a[30], ret, check = 30;
char c;
string s;

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		a[s[i] - 'A']++;
	}
	
	for(int i = 0; i < 26; i++){
		if(a[i] % 2){
			ret++;
			check = i;
		}
	}
	if(ret > 1){
		cout << "I'm Sorry Hansoo";
		return 0;	
	}
	
	for(int i = 0; i < 26; i++){
		int j = a[i];
		j = j / 2;
		while(j--){
			c = 'A' + i;
			cout << c;
		}
	}
	
	if(check < 26){
		c = 'A' + check;
		cout << c;
	}
	
	for(int i = 25; i >= 0; i--){
		int j = a[i];
		j = j / 2;
		
		while(j--){
			c = 'A' + i;
			cout << c;
		}
	}
	return 0;
}
