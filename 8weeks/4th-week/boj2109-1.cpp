#include<bits/stdc++.h>
using namespace std;

int n, p, d, ret;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p >> d;
		v.push_back({d, p});	
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){ // v[i].first날짜 안에 할 수 있는 것들 중에 가장 value가 높은것들로 채운다는 것. 
		pq.push(v[i].second);
		if(pq.size() > v[i].first){
			pq.pop();
		}
	}
	
	while(pq.size()){
		ret += pq.top();
		pq.pop();	
	}
	
	cout << ret;
	return 0;
}
