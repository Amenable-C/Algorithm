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
		
		if(isdigit(s[0])){ // ������ ���, key�� ã�� 
			cout << map1[stoi(s)] << "\n"; 
		}
		else{ // ������ ���, value�� ã�� 
			cout << map2[s] << "\n";	
		}
			
	}
	
}
