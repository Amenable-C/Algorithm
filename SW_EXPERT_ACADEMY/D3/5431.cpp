#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int t, n, k, num;

int main(){
	cin >> t;	
	for(int _t = 1; _t <= t; _t++){
		cin >> n >> k;
		vector<int> v;
		
		for(int i = 0; i < k; i++){
			cin >> num;
			v.push_back(num);
		}
		
		cout << "#" << _t << " ";
		for(int i = 1; i <= n; i++){
			if(find(v.begin(), v.end(), i) != v.end())
				continue;
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
