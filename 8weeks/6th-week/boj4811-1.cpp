#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, dp[34][34];

ll go(int w, int h){
	if(w == 0 && h == 0)
		return 1;
	if(dp[w][h])
		return dp[w][h];
	
	ll &ret = dp[w][h];
	if(w > 0){
		ret += go(w - 1, h + 1);	
	}
	if(h > 0){
		ret += go(w, h - 1);
	}
	return ret;
}

int main(){
	while(true){
		cin >> n;
		if(n == 0)
			break;
			
		cout << go(n, 0) << "\n";	
	}
	return 0;
}
