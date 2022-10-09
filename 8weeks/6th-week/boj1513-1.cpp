#include<bits/stdc++.h>
using namespace std;

int n, m, c, _n, _m, a[54][54], dp[54][54][54][54];
int _mod = 1000007;

int go(int y, int x, int cnt, int prev){
	// 범위를 벗어난 경우
	if(y > n || x > m){
		return 0;
	}
	// 도착한 경우
	if(y == n && x == m){
		if(cnt == 0 && a[y][x] == 0){
			return 1;
		}
		else if(cnt == 1 && a[y][x] > prev){
			return 1;
		}
		return 0;
	}
	
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1)
		return ret;
		
	ret = 0;
	if(a[y][x] == 0){ // 오락실이 아닌 경우 
		ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % _mod;
	}
	else if(a[y][x] > prev){ // 오락실인 경우 
		ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % _mod;
	}
	return ret; // 현재 오락실이 이전꺼보다 크지 않으면 0이 return 됨 
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){
		cin >> _n >> _m;
		a[_n][_m] = i;
	}
	
	for(int i = 0; i <= c; i++){
		cout << go(1, 1, i, 0) << " ";	
	}
	return 0;
}


