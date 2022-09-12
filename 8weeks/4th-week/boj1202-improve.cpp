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
			ret += pq.top(); // ���⼭ �ݺ����� ���°� �ƴ϶� ���ǹ��̶� ���� value�� ������ �ϳ��� ������ ��. // �׸��� while�� �۵� ���Ѱ�쿡�� size�� ��������ν� ����ؼ� �ִ� ���� ã������ �ϴ°�!!! 
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}
