#include<bits/stdc++.h>
using namespace std;

int changed;
string s;
char c;

int main(){
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if(s[i] - 'a' >= 0 && s[i] - 'a' < 26){
			changed = (s[i] - 'a' + 13) % 26;
			c = 'a' + changed;
			cout << c;		
		}
		else if(s[i] - 'A' >= 0 && s[i] - 'A' < 26){
			changed = (s[i] - 'A' + 13) % 26;
			c = 'A' + changed;
			cout << c;		
		}
		else{
			cout << s[i];	
		}
	}
	return 0;
}
