#include<bits/stdc++.h>
using namespace std;

int t, flag, cnt;
string s;

int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		cin >> s;
		flag = 0;
		cnt = 0;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1' && flag == 0){
				cnt++;
				flag = 1;
			}
			else if(s[i] == '0' && flag == 1){
				cnt++;
				flag = 0;	
			}
		}
		
		cout << "#" << _t << " " << cnt << "\n";
		
	}
	return 0;
}
