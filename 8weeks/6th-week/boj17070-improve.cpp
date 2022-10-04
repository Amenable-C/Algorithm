#include<bits/stdc++.h>
using namespace std;

int n, a[24][24], dp[24][24][3];

bool check(int y, int x, int d){ // ���� �ִ��� Ȯ�� 
	// ���� ���� �� �ִ��� üũ 
	if(d == 0 || d == 2){
		if(!a[y][x])
			return true;
	}
	// �밢���� �� �ִ��� üũ 
	else if(d == 1){
		if(a[y][x] == 0 && a[y-1][x] == 0 && a[y][x-1] == 0) // ȸ���Ҷ� �� ��ĭ�̾�� �ϴ� ĭ�� üũ 
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

	dp[1][2][0] = 1; // �������� 0�̰� dp[1][2][0]�� 1�̹Ƿ� �̰� �ʱ� ���� �Ϸ� �Ȱ� 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			// ���� 
			if(check(i, j + 1, 0))
				dp[i][j + 1][0] += dp[i][j][0];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][0];
			// ���� 
			if(check(i + 1, j, 2))
				dp[i + 1][j][2] += dp[i][j][2];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][2];
			
			// �밢�� 
			if(check(i, j + 1, 0))
				dp[i][j + 1][0] += dp[i][j][1];
			if(check(i + 1, j, 2))
				dp[i + 1][j][2] += dp[i][j][1];
			if(check(i + 1, j + 1, 1))
				dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	
	int ret = dp[n][n][0]; // �������� ���� ������� ������ ��� 
	ret += dp[n][n][1]; // �������� �밢�� ������� ������ ��� 
	ret += dp[n][n][2]; // �������� ���� ������� ������ ���  
	
	cout << ret;
	return 0;
}
