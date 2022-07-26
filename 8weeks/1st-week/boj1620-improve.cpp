#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	map<int, string> map1;
	map<string, int> map2;
	
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		map1[i+1] = s;
		map2[s] = i+1;
	}
	
	for(int i = 0; i < k; i++){
		cin >> s;
		
		if(isdigit(s[0])){ // 숫자인 경우, key로 찾기 
			cout << map1[stoi(s)] << "\n"; 
		}
		else{ // 문자인 경우, value로 찾기 
			cout << map2[s] << "\n";	
		}
			
	}
	
}
