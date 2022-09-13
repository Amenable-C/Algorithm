#include<bits/stdc++.h>
using namespace std;

long n, k, mi, vi, ret;


int main(){
	cin >> n >> k;
	
	vector<pair<long, long>> v(n);
	long c[k];
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
		
	}
	
	for(int i = 0; i < k; i++){
		cin >> c[i];	
	}
	
	
	sort(v.begin(), v.end());
	sort(c, c + k);
	
	int j = 0;
	priority_queue<int> pq;
	for(int i = 0; i < k; i++){
		while(j < n && v[j].first <= c[i]){
			pq.push(v[j].second); // 이렇게 하면 가능한 것 중에 가장 value가 높은것을 top으로 확인 가능!!!!! 
			j++;
		}
		
		if(pq.size()){ // 어짜피 가방을 k번 밖에 못 쓰는거 
			ret += pq.top();
			pq.pop();	
			
		}
	}
	cout << ret;
	return 0;
}
