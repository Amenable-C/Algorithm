#include<bits/stdc++.h>
using namespace std;

int n, c, p, dp[10001];
float m, _p;

int main(){
	while(1){
		cin >> n >> m;
		if(n == 0)
			break;
		
		int cost = m * 100;
		fill(dp, dp + 10001, 0);
		
		for(int i = 0; i < n; i++){
			cin >> c >> _p;
			p = _p * 100;
			
			for(int j = p; j <= cost; j++){
				dp[j] = max(dp[j], dp[j - p] + c);	
			}
		}
		cout << dp[cost] << "\n";
	}
	return 0;
}
