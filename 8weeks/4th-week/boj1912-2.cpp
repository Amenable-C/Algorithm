#include<bits/stdc++.h>
using namespace std;

int n, a, sum, ret = -1004;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		sum += a;
		ret = max(ret, sum);
		if(sum < 0)
			sum = 0;
		
	}
	cout << ret;
	return 0;
}
