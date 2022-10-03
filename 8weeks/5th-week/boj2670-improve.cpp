#include<bits/stdc++.h>
using namespace std;

int n;
double a[10001], ret, b;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	// 최대곱을 구하는 방법 3가지
	// 1. 앞 부분의 최대곱을 사용
	// 2. 앞 부분의 최대곱과 새로 들어온 값의 곱을 사용
	// 3. 새로 들어온 값이 최대곱으로 설정. 
	double b = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > b * a[i]) // 3
			b = a[i];
		else //
			b *= a[i]; // 2
			
		ret = max(b, ret);	// 1
	}
	
	printf("%.3lf", ret + 0.00001);
	return 0;
}
