#include<bits/stdc++.h>
using namespace std;

int n, a[1004], _max, ret;

int main(){
	for(int i = 1; i <= 10; i++){
		ret = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		
		for(int j = 2; j < n - 2; j++){
			_max = 0;
			for(int k = j - 2; k <= j + 2; k++){
				if(k == j)
					continue;
				
				_max = max(_max, a[k]);
			}
			ret += max(0, a[j] - _max);
		}
		cout << "#" << i << " " << ret << "\n";
	}
	return 0;
}
