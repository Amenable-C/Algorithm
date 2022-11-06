#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, a[11], ret;
vector<ll> v;

void go(ll idx, ll cnt, ll sum){
	if(cnt == 3){
		if(find(v.begin(), v.end(), sum) == v.end())
			v.push_back(sum);
		return;	
	}
	if(idx == 7){
		return;
	}
	
	go(idx + 1, cnt + 1, sum + a[idx]);
	go(idx + 1, cnt, sum);
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	
	for(int _t = 1; _t <= t; _t++){
		memset(a, 0, sizeof(a));
		v.clear();
		
		
		for(int i = 0; i < 7; i++){
			cin >> a[i];
		}
		
		go(0, 0, 0);

		sort(v.begin(), v.end(), greater<>());
		
		cout << "#" << _t << " " << v[4] << "\n";
	}
	
	return 0;
}
