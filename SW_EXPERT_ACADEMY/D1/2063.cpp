#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);	
	}
	sort(v.begin(), v.end());
	
	cout << v[n/2];
	return 0;
}
