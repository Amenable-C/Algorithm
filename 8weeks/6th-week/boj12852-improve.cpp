#include<bits/stdc++.h>
using namespace std;

int dp[1000004], n;
const int INF = 987654321;

void go(int here){
	if(here == 0)
		return;
		
	cout << here << " ";
	
	if(here % 3 == 0 && dp[here] == (dp[here / 3] + 1))
		go(here / 3);
	else if(here % 2 == 0 && dp[here] == (dp[here / 2] + 1))
		go(here / 2);
	else if((here - 1 >= 0) && (dp[here] == (dp[here - 1] + 1)))
		go(here - 1);
	return;
		
}

int main(){
	cin >> n;
	fill(dp, dp + 1000004, INF);
	dp[1] = 0;
	for(int i = 1; i <= n; i++){ // n은 이전 단계에 있을 수 있는 경우에서 +1을 하면 됨 == 계속 해서 이전 단계가 최소화가 되어야 함. 
		if(!(i % 3)){
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		if(!(i % 2)){
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << "\n"; // 경우의 수 출력
	go(n); // 아무거나 방법 한 가지 출력 
	return 0;
	
}
