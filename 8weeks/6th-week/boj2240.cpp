#include<bits/stdc++.h>
using namespace std;

int t, w, a[1004], dp[1004][2][34];

int go(int time, int pos, int count){
	if(count < 0){
		return -1e9;
	}
	if(time == t){ 
		return 0;
	}
	
	int &ret = dp[time][pos][count];
	if(~ret)
		return ret;
		
	return ret = max(go(time + 1, pos^1, count - 1), go(time + 1, pos, count)) + (pos == a[time] - 1 ? 1 : 0);
}



int main(){
	cin >> t >> w;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < t; i++){
		cin >> a[i];	
	}
	
	cout << max(go(0, 0, w), go(0, 1, w-1));
	return 0;	
}
