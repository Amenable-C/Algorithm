#include<bits/stdc++.h>
using namespace std;

long long n, m, v, k, a, j, ret;
vector<pair<long long, long long>> vec;
vector<long long> vec_k;
priority_queue<long long> pq;

int main(){
	cin >> n >> k;
	for(long long i = 0; i < n; i++){
		cin >> m >> v;
		vec.push_back({m, v});
	}
	
	for(long long i = 0; i < k; i++){
		cin >> a;
		vec_k.push_back(a);	
	}
	
	sort(vec.begin(), vec.end());
	sort(vec_k.begin(), vec_k.end());
	
	for(long long i = 0; i < k; i++){
		while(j < n && vec[j].first <= vec_k[i]){
			pq.push(vec[j++].second);	
		}
		if(pq.size()){	
			ret += pq.top();
			pq.pop();	
		}
	}
	
	cout << ret;
	return 0;
}
