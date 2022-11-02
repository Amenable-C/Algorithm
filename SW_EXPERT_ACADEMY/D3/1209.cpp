#include<bits/stdc++.h>
using namespace std;

int t, sum, ret, a[104][104];

int main(){
	
	for(int _t = 1; _t <= 10; _t++){
		memset(a, 0, sizeof(a));
		sum = 0, ret = 0;
		
		cin >> t;	
		
		// 가로 끝 
		for(int i = 0; i < 100; i++){
			sum = 0;
			for(int j = 0; j < 100; j++){
				cin >> a[i][j];
				sum += a[i][j];
			}
			ret = max(ret, sum);
		}
		
		// 세로
		for(int i = 0; i < 100; i++){
			sum = 0;
			for(int j = 0; j < 100; j++){
				sum += a[j][i];
			}
			ret = max(ret, sum);
		}
		
		// 대각선 00, 11, 22, ... , 99, 99
		sum = 0;
		for(int i = 0; i < 100; i++){
			sum += a[i][i];
		}
		ret = max(ret, sum);
		
		// 대각선 0, 99 / 1, 98 / ... / 99, 0
		sum = 0;
		for(int i = 0; i < 100; i++){
			sum += a[i][99-i];
		}
		ret = max(ret, sum);
		
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
