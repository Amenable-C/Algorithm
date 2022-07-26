#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	map<int, string> map1;
	map<string, int> map2;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		map1.insert(pair<int, string>(i+1, s));
		map2.insert(pair<string, int>(s, i+1));
	}
	
	string t="";
	for(int i = 0; i < k; i++){
		cin >> t;
		if(isdigit(t[0])){ // ������ ���, key�� ã�� 
			cout << map1.find(stoi(t))->second << endl; 
		}
		else{ // ������ ���, value�� ã�� 
			cout << map2.find(t)->second << endl;	
		}
	}
}
