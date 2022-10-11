#include<bits/stdc++.h>
using namespace std;

int n, k, t, ret = -987654321;
int s[100004];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> t;	
		s[i] = s[i - 1] + t;
	}
	
	for(int i = k; i <= n; i++){
		ret = max(ret, s[i] - s[i - k]);
	}
	cout << ret;
	return 0;
}
