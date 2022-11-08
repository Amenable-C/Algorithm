#include<bits/stdc++.h>
using namespace std;

int t, n, a[10000004], ret;
string s;

int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		memset(a, 0, sizeof(a));
		ret = 0;
		cin >> n >> s;
		
		a[0] = 1 % (n - 1);
		
		for(int i = 1; i < s.size(); i++){
			a[i] = (a[i - 1] * n) % (n - 1);
		}
		
		for(int i = 0; i < s.size(); i++){
			ret += (int)(s[i] - '0') * a[s.size() - i - 1];
		}
		ret %= (n - 1);
		
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
