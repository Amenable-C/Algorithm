#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, dp[31][31];

ll go(int whole, int not_whole){
	if(whole == 0 && not_whole == 0)
		return 1; // go(1 - 1, 0), go(0, 1 - 1)이라는 행위 자체가 1을 리턴 받음. 
	if(dp[whole][not_whole]) // 이미 왔던 길이면 새로운 길을 더 이상 개척(?)하지 않는 것 => ret이 증가하지 않음!!!
		return dp[whole][not_whole];
	
	// 꺼내는 것을 기준으로 한다 == 남아 있는 것을 기준으로 한다.  
	ll &ret = dp[whole][not_whole];
	if(whole > 0)
		ret += go(whole - 1, not_whole + 1);
	if(not_whole > 0)
		ret += go(whole, not_whole - 1);
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
