#include<bits/stdc++.h>
using namespace std;

int n, m, num, ret = 987654321, cnt, minLen = 987654321;
vector<pair<int , int>> h;
vector<pair<int , int>> c;
vector<vector<int>> cList;

void combi(int start, vector<int> v){
	if(v.size() == m){
		cList.push_back(v);
		return;
	}
	
	for(int i = start + 1; i < c.size(); i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> num;
			if(num == 1){
				h.push_back({i, j});		
			}
			else if(num == 2){
				c.push_back({i, j});
			}
		}
	}
	
	vector<int> v;
	combi(-1, v);
	
	for(vector<int> i : cList){
		cnt = 0;
		for(pair<int, int> j : h){
			minLen = 987654321;
			for(int k : i){
				minLen = min(minLen, abs(j.first - c[k].first) + abs(j.second - c[k].second));
			}
			cnt += minLen;
		}
		ret = min(ret, cnt);
	}
	cout << ret;
	return 0;
}
