#include<bits/stdc++.h>
using namespace std;

int t, len, flag; 
string s;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		
		cin >> s;
		
		for(int len = 1; len <= 10; len++){
			flag = 0;
			for(int j = 0; j < len; j++){
				int p = j + len;
				while(p < 30){
					if(s[j] != s[p]){
						flag = 1;
					}
					p += len;
				}
			}
			if(flag == 0){
				cout << "#" << i << " " << len << "\n";
				break;	
			}		
		}
	}
	return 0;
	
}
