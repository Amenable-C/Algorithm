#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k, n, a[10004], low = 1, high, mid, ret;

ll check(ll len){
	ll cnt = 0;
	for(int i = 0; i < k; i++){
		cnt += a[i] / len;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> a[i];
		high = max(high, a[i]);
	}
	
	
	while(low <= high){
		mid = (low + high) / 2;
		if(check(mid) >= n){
			ret = max(ret, mid);
			low = mid + 1;
		}
		else{
			high = mid - 1;	
		}
	}
	
	cout << ret;
	return 0;
}
