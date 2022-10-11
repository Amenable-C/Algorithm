#include<bits/stdc++.h>
using namespace std;

int t, n, ret;
string a, b;
map<string, int> mp;

int main(){
	cin >> t;
	while(t--){
		ret = 1;
		mp.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			mp[b]++;	
		}
		
		for(auto it : mp){
			ret *= it.second + 1;	
		}
		ret--;
		cout << ret << "\n";
	}
	
}
