#include<bits/stdc++.h>
using namespace std;

long long s, e, cnt[100001], n, a[100001];
long long ret;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}

	while(e < n){
		if(!cnt[a[e]]){ // 구간 안에 있는 수와 중복되는 것이 없을 경우 
			cnt[a[e]]++;
			e++;
		}
		else{ // 여기서는 e가 바뀌는게 아닌 s만 바뀌는 거라서 s가 중복이 없을동안 계속 따라오는것! 
			ret += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	 
	ret += (e - s) * (e - s + 1) / 2;
	cout << ret;
	return 0; 
}
