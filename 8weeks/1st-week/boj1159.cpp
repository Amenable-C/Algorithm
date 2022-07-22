#include <bits/stdc++.h>
using namespace std;


int a[26];
int main(){
	int num;
	cin >> num;
	
	for(int i = 0; i < num; i++){
		string s;
		cin >> s;
		
		a[s[0] - 'a']++;
	}
	
	bool check = false;
	for(int i = 0; i < 26; i++){
		if(a[i] >= 5){
			check = true;
			cout << char(i + 'a');
		}
	}
	if(check == false)
		cout << "PREDAJA";
}
