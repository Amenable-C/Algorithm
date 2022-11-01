#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 가장 큰거 고르고 // 오른쪽 범위에서 가장 큰거 고르고 // 오른쪽 범위에서 가장 큰거 고르기 

ll t, n, num, ret, _left, a[1000004], _max;



int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		ret = 0;
		_left = 0;
		_max = 0;
		vector<pair<ll, ll>> v; 
		
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
			
			v.push_back({a[j], j});
		}
		sort(v.rbegin(), v.rend());
		
		
		for(int j = 0; j < v.size(); j++){
			if(v[j].first != _max){
				if(v[j].second >= _left){
					// a의 left부터 v[j].first전까지 더하기
					ll sum = 0;
					for(int k = _left; k < v[j].second; k++)
						sum += a[k];
					
					// "v[j].first * 개수 - 위의 값"을 ret에 넣기
					ret += v[j].first * (v[j].second - _left) - sum;
					
					// _max랑 left 새롭게 업데이트 
					_max = v[j].first;
					_left = v[j].second + 1; 
				}
			}
			
		}
		cout << "#" << i << " " << ret << "\n";
	}
	return 0;
}
