#include<bits/stdc++.h>
using namespace std;

int t, flag;
string t_s, s;

int main(){
	cin >> t;
	cin >> t_s; // 무조건 가운데 별표 한개
	int star = t_s.find("*");
	while(t--){
		flag = 0;
		cin >> s;
		
		if(t_s.size() - 1 > s.size()){
			cout << "NE\n";
			continue;	
		}
		for(int i = 0; i < star; i++){
			if(s[i] != t_s[i]){
				cout << "NE\n";
				flag = 1;
				break;
			}
		}
		
		if(flag)
			continue;
		for(int i = 0; i < t_s.size() - star - 1; i++){
			if(t_s[t_s.size() - i - 1] != s[s.size() - i - 1]){
				cout << "NE\n";
				flag = 1;
				break;	
			}				
		}
		if(!flag)
			cout << "DA\n";
	}
}
