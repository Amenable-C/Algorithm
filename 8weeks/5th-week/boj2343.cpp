#include<bits/stdc++.h>
using namespace std;

int n, m, a[100004], l, r, ret = 987654321, mid;

bool go(int mid){
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(sum + a[i] <= mid){
			sum += a[i];
		}
		else{
			cnt++;
			sum = a[i];
		}
		if(cnt == m)
			return false;
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		l = max(l, a[i]);
	}
	
	r = 987654321;
	
	
	while(l <= r){
		mid	= (l + r) / 2;
		if(go(mid)){ // 가능한 경우 
			ret = min(ret, mid);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << ret;
	return 0;
}
