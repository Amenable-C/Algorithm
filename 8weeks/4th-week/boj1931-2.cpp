#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

int n, a, b, ret, t;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({b, a});
	}
	
	sort(v.begin(), v.end());
	
	t = v[0].first;
	ret++;
	for(int i = 1; i < n; i++){
		if(v[i].second >= t){
			t = v[i].first;
			ret++;
		}
	}
	cout << ret;
	return 0;
}

