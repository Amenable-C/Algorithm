#include<bits/stdc++.h>
using namespace std;

long long n, a, b, ret;
vector<pair<long, long>> v;
priority_queue<long, vector<long>, greater<long>> pq;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		pq.push(v[i].second);
		if(pq.size() > v[i].first){
			pq.pop();
		}
	}
	
	if(pq.size()){
		while(pq.size()){
			ret += pq.top();
			pq.pop();
		}
		cout << ret;
	}
	else{
		cout << 0;	
	}
	
	return 0;
}
