#include<bits/stdc++.h>
using namespace std;

int n, l, s, e, pos, ret;
vector<pair<int, int>> v;

int main(){
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> s >> e;
		v.push_back({s, e});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		if(pos < v[i].first){ // 1. 哭率
			int num = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
			ret += num;
			pos = v[i].first + num * l;
		}
		else if(pos < v[i].second){ // 2. 啊款单 
			int num = (v[i].second - pos) / l + ((v[i].second - pos) % l ? 1 : 0);
			ret += num;
			pos += num * l;
		}
		else{ // 3. 坷弗率  
			continue;
		}
	}
	
	cout << ret;
	return 0;
}

