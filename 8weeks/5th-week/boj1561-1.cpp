#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[10004], lo = 1, hi = 60000000004, ret, temp;

bool go(ll mid){
	ll cnt = m;
	for(ll i = 0; i < m; i++){
		cnt += mid / a[i];	
	}
	return cnt >= n;
}


int main(){
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}
	
	if(n <= m){
		cout << n;
		return 0;	
	}
	
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		if(go(mid)){
			ret = mid;
			hi = mid - 1;
		
		}
		else{
			lo = mid + 1;
		}
	}
	
	temp = m;
	for(ll i = 0; i < m; i++){
		temp += (ret - 1) / a[i];
	}
	
	for(ll i = 0; i < m; i++){
		if(ret % a[i] == 0)
			temp++;
		if(temp == n){
			cout << i + 1;
			return 0;	
		}
	}
	return 0;
}
