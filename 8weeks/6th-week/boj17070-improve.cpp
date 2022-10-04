#include<bits/stdc++.h>
using namespace std;

int n, a[24][24], dp[24][24][3];

bool check(int y, int x, int d){ // 벽이 있는지 확인 
	// 가로 세로 벽 있는지 체크 
	if(d == 0 || d == 2){
		if(!a[y][x])
			return true;
	}
	// 대각선에 벽 있는지 체크 
	else if(d == 1){
		if(a[y][x] == 0 && a[y-1][x] == 0 && a[y][x-1] == 0) // 회전할때 꼭 빈칸이어야 하는 칸들 체크 
			return true;
	}
	return false; 
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];	
		}
	}

	dp[1][2][0] = 1; // 나머지는 0이고 dp[1][2][0]만 1이므로 이게 초기 세팅 완료 된거 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			// 가로 
			if(check(i, j + 1, 0))
				dp[i][j + 1][0] += dp[i][j][0];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][0];
			// 세로 
			if(check(i + 1, j, 2))
				dp[i + 1][j][2] += dp[i][j][2];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][2];
			
			// 대각선 
			if(check(i, j + 1, 0))
				dp[i][j + 1][0] += dp[i][j][1];
			if(check(i + 1, j, 2))
				dp[i + 1][j][2] += dp[i][j][1];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	
	int ret = dp[n][n][0]; // 마지막에 가로 모양으로 도착한 경우 
	ret += dp[n][n][1]; // 마지막에 대각선 모양으로 도착한 경우 
	ret += dp[n][n][2]; // 마지막에 세로 모양으로 도착한 경우  
	
	cout << ret;
	return 0;
}
