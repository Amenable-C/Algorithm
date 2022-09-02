#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000];
vector<int> v[15];


void go(int s, int e, int level){
	if(s > e)
		return;
	if(s == e){
		v[level].push_back(a[s]);
		return;	
	}
	
	int _mid = (s + e) / 2;
	v[level].push_back(a[_mid]);
	go(s, _mid - 1, level + 1);
	go(_mid + 1, e, level + 1);
}


int main(){
	cin >> n;
	int _end = pow(2, n) - 1;
	
	for(int i = 0; i < _end; i++){
		cin >> a[i];
	}
	
	go(0, _end, 1);

	for(int i = 1; i <= n; i++){
		for(int j : v[i])
			cout << j << " ";
		cout << "\n";	
	}
	
	return 0;
}
