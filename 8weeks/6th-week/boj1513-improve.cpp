#include<bits/stdc++.h>
using namespace std;

int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;

int go(int y , int x, int cnt, int prev){
	if(y > n || x > m) // 범위를 벗어나는 경우 
		return 0;
	if(y == n && x == m){ // 학원(마지막 지점)에 도착한 경우 
		if(cnt == 0 && a[y][x] == 0) // 도착점이랑 마지막 오락실이 일치하지 않는 경우. 
			return 1;
		if(cnt == 1 && a[y][x] > prev) // 도착점이랑 마지막 오락실이 일치하는 경우.  
			return 1;
		return 0; // 조건에 맞지 않은 경우는 0을 return 
	}
	
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1){ // 이미 정해진 경우 
		return ret; 
	}
	
	ret = 0;
	if(a[y][x] == 0){ // 현재 위치가 오락실이 아닌 경우.
		ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod; 
	} 
	else if(a[y][x] > prev){ // 현재 위치가 오락실인 경우. 
		ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;		
	}
	return ret;
}
 


int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){ // 초기 prev를 0으로 설정할거라서 1부터 시작. 
		cin >> y >> x;
		a[y][x] = i; // 오락실의 번호를 부여하면서 위치 저장	
	}
	
	for(int i = 0; i <= c; i++){ // 0개 방문, 1개 방문, 2개 방문, ... , c개 방문 
		cout << go(1, 1, i, 0) << " ";
	}
	return 0;
}
