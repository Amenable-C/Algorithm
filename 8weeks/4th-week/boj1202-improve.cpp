#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, ret, temp1, temp;

int main(){
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	vector<ll> vv(k);
	
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	
	for(int i = 0; i < k; i++){
		cin >> vv[i];	
	}
	
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	
	priority_queue<ll> pq;
	
	int j = 0;
	for(int i = 0; i < k; i++){
		while(j < n && v[j].first <= vv[i])
			pq.push(v[j++].second);
			
		if(pq.size()){
			ret += pq.top(); // 여기서 반복문을 도는게 아니라 조건문이라서 제일 value가 높은거 하나만 선택이 됨. // 그리고 while이 작동 안한경우에도 size를 고려함으로써 계속해서 최대 값을 찾을려고 하는것!!! 
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}
