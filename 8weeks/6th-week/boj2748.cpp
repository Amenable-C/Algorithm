#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, dp[100];

int main(){
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	
	if(n < 2){
		cout << dp[n];
		return 0;	
	}
	
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n];
	return 0;
}
