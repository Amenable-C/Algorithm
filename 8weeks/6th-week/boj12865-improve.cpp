#include<bits/stdc++.h>
using namespace std;

int n, k, w, v, dp[1000001];

int main(){
	cin >> n >> k;
	while(n--){
		cin >> w >> v;
		for(int j = k; j >= w; j--){
			dp[j] = max(dp[j], dp[j - w] + v);	
		}
	}
	cout << dp[k];
	return 0;
}



