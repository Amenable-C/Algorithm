#include <bits/stdc++.h>
using namespace std;

string s, m;
int n;
int a[30];

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		a[s[0] - 'a']++;
	}
	
	for(int i = 0; i <= 'z' - 'a'; i++){
		if(a[i] >= 5){
			m += 'a' + i;
		}
	}
	
	if(m.size()){
		cout << m;
	}
	else{
		cout << "PREDAJA";
	}
	
	return 0;
}
