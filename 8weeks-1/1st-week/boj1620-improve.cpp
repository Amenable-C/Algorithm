#include<bits/stdc++.h>
using namespace std;

int n, m, temp;
string s;
map<int, string> mp1;
map<string, int> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		mp1[i] = s;
		mp2[s] = i;
	}
	
	for(int i = 0; i < m; i++){
		cin >> s;	
		if(s[0] - '0' > 0 && s[0] - '0' <= 9){
			cout << mp1[stoi(s)] << "\n";	
		}
		else{
			cout << mp2[s] << "\n";
		}
	}
	
	return 0;
	
	
}
