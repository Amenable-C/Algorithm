#include<bits/stdc++.h>
using namespace std;

int n, cnt, p;
string target, s;

int main(){
	
	for(int _t = 1; _t <= 10; _t++){
		cnt = 0;
		p = 0;
		
		cin >> n;
		cin >> target;
		cin >> s;
		
		while(s.find(target, p) != string::npos){
			cnt++;
			p = s.find(target, p) + target.size();				
		}
		
		cout << "#" << _t << " " << cnt << "\n";
	}
	return 0;
}
