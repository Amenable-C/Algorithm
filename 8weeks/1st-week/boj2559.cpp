#include <bits/stdc++.h>
using namespace std;


int n, k;
int main(){
	cin >> n >> k;
	
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += a[i];	
	}
	
	int max = 0;
	max = sum;
	for(int i = k; i < n; i++){
		sum -= a[i - k];
		sum += a[i];
		if(max < sum)
			max = sum;
	}
	
	cout << max;
	return 0;
	
	
}
