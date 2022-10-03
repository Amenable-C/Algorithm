#include<bits/stdc++.h>
using namespace std;
#define prev abc

typedef long long ll;
ll n, a[1000004], prev[1000004], cnt[1000004], ret;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin >> n;
	
	// 여기에 초기화 해야 함
	memset(prev, -1, sizeof(prev));
	memset(cnt, 0, sizeof(cnt));
	 
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		for(ll j = 0; j < i; j++){
			if(a[j] < a[i] && cnt[j] >= cnt[i]){
				prev[i] = j;
				cnt[i] = cnt[j] + 1;
				ret = i;
			}
		}
	}

	cout << cnt[ret] + 1 << "\n";
	
	while(true){
		v.push_back(a[ret]);
		ret = prev[ret];
		
		if(ret == -1)
			break;	
	}
	
	for(ll i = v.size() - 1; i >= 0; i--){
		cout << v[i] << " ";
	}

	return 0;
}
