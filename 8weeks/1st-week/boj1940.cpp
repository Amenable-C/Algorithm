#include <bits/stdc++.h>
using namespace std;

int a[10000000];

map<int, int> _map;

int main(){
	int n, m;
	
	cin >> n >> m;
	
	int z;
	for(int i = 0; i < n; i++){
		cin >> z;
		_map[z] = z;
	}
	
	int count = 0;
	for(int i = 0; i <= m/2; i++){
		if(_map.find(i)->second)
			if(_map.find(m-i)->second)
				count++; 
	}
	
	if(m % 2 == 0){
		if(_map.find(m / 2)->second)
			count--;	
	}
		
	cout << count;
	
}
