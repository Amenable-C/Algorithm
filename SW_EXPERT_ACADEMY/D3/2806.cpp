#include<bits/stdc++.h>
using namespace std;

int t, n, ret, y, x, a[15][15];
vector<pair<int, int>> v;

// 말을 놓으면 y를 상승시켜야 하고
// 말을 놓지 않으면 x를 상승시켜야함.


bool check(int y, int x){
	for(pair<int, int> i : v){
		// y 체크
		
		// x 체크
		if(i.second == x)
			return false;
		// 대각선 체크
		if(abs(i.first - y) == abs(i.second - x))
			return false;
	}
	return true; 
}

void dfs(int y){
	if(y == n){ // 다 넣은 경우 
		ret++;	
	}
	
	for(int i = 0; i < n; i++){
		if(check(y, i)){
			v.push_back({y, i});
			dfs(y + 1); 
			v.pop_back();
		}
		else{
			continue;
		}	
	}
}


int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(a, 0, sizeof(a));
		ret = 0;
		cin >> n;
		// dfs로 풀어야 함
		
		dfs(0);
		cout << "#" << i << " " << ret << "\n";		
	}
}
