#include<bits/stdc++.h>
using namespace std;

int n, dp[104], cost[104], happy[104];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> cost[i];
	for(int i = 0; i < n; i++)
		cin >> happy[i];
		
	for(int i = 0; i < n; i++){
		for(int j = 100; j > cost[i]; j--){
			dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
		}
	}
	cout << dp[100];
	return 0;
}
