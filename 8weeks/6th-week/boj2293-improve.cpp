#include<bits/stdc++.h>
using namespace std;

int n, k, temp, dp[10001];

int main(){
	cin >> n >> k;
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> temp;
		
		for(int j = temp; j <= k; j++){
			dp[j] += dp[j - temp];
		}
	}
	cout << dp[k];
	return 0;
}
