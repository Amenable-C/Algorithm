#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, c, a[1000004], lo = 1, hi, ret, sum;

bool go(int mid){
	int cnt = 0;
	for(int i = 0; i < s; i++){
		cnt += (a[i] / mid);
	}
	
	if(cnt >= c)
		return true;
	else
		return false;
}

int main(){
	cin >> s >> c;
	for(int i = 0; i < s; i++){
		cin >> a[i];
		hi = max(hi, a[i]);
		sum += a[i];
	}
	
	while(lo <= hi){
		long long mid = (lo + hi) / 2;
		if(go(mid)){
			ret = max(ret, mid);
			lo = mid + 1;
		}
		else{
			hi = mid - 1;	
		}
	}

	cout << sum - ret * c;
	return 0;
}
