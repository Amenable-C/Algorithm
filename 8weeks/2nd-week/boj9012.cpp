#include <bits/stdc++.h>
using namespace std;

int lcnt, rcnt, n;
string s;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '(')
				lcnt++;
			else
				rcnt++;
				
			if(rcnt > lcnt){
				break;
			}
		}
		if(rcnt != lcnt){
			cout << "NO" << endl;
			lcnt = rcnt = 0;
			continue;
		}

		cout << "YES" << endl;
		lcnt = rcnt = 0;
	}
	
	return 0;
}
