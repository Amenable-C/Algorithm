#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, dp[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	
	dp[0] = 1;
	// 중복을 허용안하기 때문에 1, 2, 3을 순서대로 넣어줘야 함!!!! 
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 10000; j++){
			if(j - i >= 0)
				dp[j] += dp[j - i];
		}
	}
	
	
	while(t--){
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
