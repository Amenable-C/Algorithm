#include<bits/stdc++.h>
using namespace std;

int t, n, l, num, cal, ret, cnt;
vector<pair<int, int>> v;

void dp(int idx, int total_cal, int total_num){
	if(idx == n){
		if(total_cal <= l){
			ret = max(ret, total_num);	
		}
		return;
	}
	
	dp(idx + 1, total_cal + v[idx].first, total_num + v[idx].second);
	dp(idx + 1, total_cal, total_num);
	
	return;
}




int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		v.clear();
		ret = 0;
		cin >> n >> l;
		
		for(int i = 0; i < n; i++){
			cin >> num >> cal;
			v.push_back({cal, num});
		}
		
		dp(0, 0, 0);
		
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
