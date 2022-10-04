#include<bits/stdc++.h>
using namespace std;

int dp[1004][2][34], n , m, b[1004];

int go(int idx, int tree, int cnt){
	// 기저사례
	if(cnt < 0)
		return -1e9;
	if(idx == n) // 주어진 시간에서 멈추는 것 // 0으로 해서 계산 안하기 
		return cnt == 0 ? 0 : -1e9; 
	
	// 메모이제이션
	int &ret = dp[idx][tree][cnt];
	if(~ret) // 비트 NOT연산자 // x -> -x -1로 됨 // 값이 하날도 입력된 경우 return ret을 함. 
		return ret; 
	
	// 로직	
	return ret = max(go(idx + 1, tree^1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1); // 움직이는 경우 vs 안 움직이는 경우 
	
}

int main(){
	// 초기화 
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	cout << max(go(0, 1, m - 1), go(0, 0, m)); // 시작 위치는 0 
	return 0; 
}
