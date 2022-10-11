#include<bits/stdc++.h>
using namespace std;

int n, a[30], flag;
string s;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		a[s[0] - 'a']++;
	}
	
	for(int i = 0;i < 28; i++){
		if(a[i] >= 5){
			char c = 'a' + i;
			cout << c;
			flag = 1;	
		}
	}
	
	if(flag == 0)
		cout << "PREDAJA";
	return 0;
}
