#include<bits/stdc++.h>
using namespace std;

int t, n, k, ret, a[24];

void dp(int idx, int total){
	if(total == k){
		ret++;
		return;	
	}
	if(total > k){
		return;	
	}
	if(idx == n){
		return;	
	}

	dp(idx + 1, total + a[idx]);
	dp(idx + 1, total);	
	return;
}


int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		ret = 0;
		memset(a, 0, sizeof(a));
		
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];	
		}
		dp(0, 0);
			
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
