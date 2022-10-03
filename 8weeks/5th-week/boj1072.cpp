#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, z, ret = 1000000000, lo = 1, hi = 1000000000;
bool flag = false;

ll go(ll mid){
	ll _x = x + mid;
	ll _y = y + mid;
	return _y * 100 / _x;
}

int main(){
	cin >> x >> y;
	z = y * 100 / x;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		if(go(mid) > z){
			ret = min(ret, mid);
			hi = mid - 1;
			flag = 1;
		}
		else{
			lo = mid + 1;	
		}
	}
	
	if(flag){
		cout << ret;
	}
	else{
		cout << -1;	
	}
	
	
	
	return 0;
}
