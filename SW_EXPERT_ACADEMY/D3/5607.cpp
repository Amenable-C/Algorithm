#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, r, ans, a;

ll MOD = 1234567891;
ll fac[1000001];

ll fermat(int N, ll mod){
	if(mod == 0)
		return 1;
	
	ll tmp = fermat(N, mod / 2);
	ll ans = (tmp * tmp) % MOD;
	
	if(mod % 2 == 0)
		return ans;
	else
		return (N * ans) % MOD;	
}


int main(){
	fac[0] = 1;
	fac[1] = 1;
	cin >> t;
	
	// 팩토리얼 먼저 구하는거 
	for(int i = 2; i <= 1000000; i++){
		fac[i] = (fac[i - 1] * i) % MOD;	
	}
	
	for(int _t = 1; _t <= t; _t++){
		cin >> n >> r;
		a = fermat((fac[r] * fac[n - r]) % MOD, MOD - 2);
		ans = (fac[n] * a) % MOD;
		cout << "#" << _t << " " << ans << "\n";
	}
	return 0;
}
