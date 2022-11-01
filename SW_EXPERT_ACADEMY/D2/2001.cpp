#include<bits/stdc++.h>
using namespace std;

int t, n, m, a[20][20], ret, sum;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(a, 0, sizeof(a));
		ret = 0;
		
		cin >> n >> m;
		
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				cin >> a[j][k];	
			}
		}
		
		for(int j = 0; j <= n - m; j++){
			for(int k = 0; k <= n - m; k++){
				sum = 0;
				for(int b = j; b < j + m; b++){
					for(int c = k; c < k + m; c++){
						sum += a[b][c];
					}
				}
				ret = max(ret, sum);
			}
		}
		cout << "#" << i << " " << ret << "\n";		
	}
	
	return 0;
}
