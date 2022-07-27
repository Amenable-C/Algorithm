#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, k;
	string key, value;
	
	cin >> n;
	
	multimap<string, string> mul_map;
	map<string, string> keys;
	int mul = 1;
	
	for(int i = 0; i < n; i++){
		cin >> k;
		
		for(int i = 0; i < k; i++){
			cin >> value >> key;
			mul_map.insert(pair<string, string>(key, value));
			keys[key] = key; 
		}
		
		for(auto it : keys){
			mul *= mul_map.count(it.second) + 1;
		}
		
		cout << mul - 1 << "\n";
		
		mul = 1;
		mul_map.clear();
		keys.clear();
	}
	
	return 0;
}
