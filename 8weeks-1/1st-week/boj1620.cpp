#include<bits/stdc++.h>
using namespace std;

int n, m, temp;
string s;
map<int, string> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		mp[i] = s;
	}
	
	for(int i = 0; i < m; i++){
		cin >> s;	
		if(s[0] - '0' > 0 && s[0] - '0' <= 9){
			cout << mp[stoi(s)] << "\n";	
		}
		else{
			for(auto it : mp){
				if(it.second == s){
					cout << it.first << "\n";
					break;
				}
			}
		}
	}
	
	return 0;
	
	
}
