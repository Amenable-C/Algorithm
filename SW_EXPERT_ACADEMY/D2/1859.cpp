#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// ���� ū�� ���� // ������ �������� ���� ū�� ���� // ������ �������� ���� ū�� ���� 

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
					// a�� left���� v[j].first������ ���ϱ�
					ll sum = 0;
					for(int k = _left; k < v[j].second; k++)
						sum += a[k];
					
					// "v[j].first * ���� - ���� ��"�� ret�� �ֱ�
					ret += v[j].first * (v[j].second - _left) - sum;
					
					// _max�� left ���Ӱ� ������Ʈ 
					_max = v[j].first;
					_left = v[j].second + 1; 
				}
			}
			
		}
		cout << "#" << i << " " << ret << "\n";
	}
	return 0;
}
