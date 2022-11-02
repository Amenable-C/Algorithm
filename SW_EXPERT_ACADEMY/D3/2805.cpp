#include<bits/stdc++.h>
using namespace std;

int t, n, a[54][54], ret;
string s;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		ret = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> s;
			for(int k = 0; k < n; k++){
				a[j][k] = s[k] - '0';
			}
		}
		
		for(int j = 0; j < n / 2; j++){
			for(int k = n / 2 - j; k < n / 2 - j + 2 * j + 1; k++){
				ret += a[j][k];
				ret += a[n - j - 1][k];
			}
		}
		
		for(int j = 0; j < n; j++){
			ret += a[n / 2][j];	
		}

		cout << "#" << i << " " << ret << "\n";
	}
	return 0;
}
