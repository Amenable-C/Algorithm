#include<bits/stdc++.h>
using namespace std;

int n, a_sum[100004], a[100004], ret = -987654321;


int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a_sum[i] = a_sum[i-1] + a[i];
	}
	
	for(int cnt = 1; cnt <= n; cnt++){
		for(int start = 0; start + cnt <= n; start++){
			int sum = a_sum[start + cnt] - a_sum[start];
			ret = max(ret, sum);
		}
	}
	
	cout << ret;
	return 0;
}
