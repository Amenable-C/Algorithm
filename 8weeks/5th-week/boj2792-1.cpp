#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, a[300004], lo = 1, hi = 0, ret = 1e18, mid;

bool check(int mid){
	int num = 0;
	for(int i = 0; i < m; i++){
		num += a[i] / mid;
		if(a[i] % mid)
			num++;
	}
	
	return n >= num;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i];	
		hi = max(hi, a[i]);
	}
	
	
	while(lo <= hi){
		mid = (lo + hi) / 2;
		
		if(check(mid)){ // mid를 더 낮출 수 있는 경우 
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else{ // mid를 더 올려야 하는 경우 
			 lo = mid + 1;
		}	
	}
	
	cout << ret;
	return 0;
}
