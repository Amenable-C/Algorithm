#include<bits/stdc++.h>
using namespace std;

int a[30];
string s;

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		a[s[i] - 'a']++;	
	}
	for(int i = 0; i < 26; i++){
		cout << a[i] << " ";	
	}
	
}
