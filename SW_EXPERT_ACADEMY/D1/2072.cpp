#include<bits/stdc++.h>
using namespace std;

int t, n, sum;

int main(){
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		sum = 0;
		for(int j = 0; j < 10; j++){
			cin >> n;
			if(n % 2 == 1){
				sum += n;
			}
		}
		cout << "#" << t << " " << sum << "\n";
	}
	return 0;
}
