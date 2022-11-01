#include<bits/stdc++.h>
using namespace std;

int t, n, a[1004], p, ret;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		ret = 0;
		p = 0;
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int j = 0; j < 1000; j++){
			cin >> n;
			a[n]++;
			if(a[n] > ret){
				p = n;
				ret = a[n];
			}
			else if(a[n] == ret && n > p){
				p = n;	
			}
		}
		cout << "#" << i << " " << p << "\n";
	}
	
	return 0;
}
